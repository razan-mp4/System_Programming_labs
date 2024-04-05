#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/random.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/list.h>

MODULE_AUTHOR("Author <https://github.com/razan-mp4>");
MODULE_DESCRIPTION("Lab 1.2, using struct list_head");
MODULE_LICENSE("MIT");

#define LIST_LEN 10
#define MSG_PREF "TEST: "

#define print_msg(msg, ...) printk(KERN_ERR MSG_PREF msg, ##__VA_ARGS__);

typedef struct {
    struct list_head lnode;
    uint32_t val;
} int_node_t;

#define ilfree(list_head) \
do { \
    int_node_t *__ptr, *__tmp; \
    list_for_each_entry_safe(__ptr, __tmp, (list_head), lnode) { \
        kfree(__ptr); \
    } \
} while(0)

#define ilprint(list_head) \
do { \
    int_node_t *__ptr; \
    print_msg("List: {"); \
    list_for_each_entry(__ptr, (list_head), lnode) { \
        printk(KERN_ERR "\t%i ", __ptr->val); \
    } \
    printk(KERN_ERR "}\n"); \
} while(0)

static struct list_head int_list = LIST_HEAD_INIT(int_list);

static void task(void) {
    int_node_t *ptr;
    list_for_each_entry(ptr, &int_list, lnode) {
        ptr->val <<= 1;
    }
}

static int __init list_module_init(void)
{
    int i;
    int ret = 0;
    print_msg("List allocation start...\n");

    for (i = 0; i < LIST_LEN; ++i) {
        int_node_t *ptr = (int_node_t *)kmalloc(sizeof(*ptr), GFP_KERNEL);
        if (!ptr) {
            print_msg("Can't alloc memory\n");
            ret = -ENOMEM;
            goto alloc_err;
        }
        get_random_bytes(&ptr->val, sizeof(ptr->val));
        list_add_tail(&ptr->lnode, &int_list);
    }

    print_msg("List allocation finish\n");
    ilprint(&int_list);

    task();
    ilprint(&int_list);

    // Task 4.1: Compute the bitwise AND of all elements in the list
    int_node_t *__ptr;
    uint32_t result = ~0;  // Initialize with all bits set to 1

    list_for_each_entry(__ptr, &int_list, lnode) {
        result &= __ptr->val;
    }

    print_msg("Bitwise AND of all elements: %i\n", result);

    // Task 4.2: Find the maximum value in the list
    uint32_t max_val = 0;

    list_for_each_entry(__ptr, &int_list, lnode) {
        if (__ptr->val > max_val) {
            max_val = __ptr->val;
        }
    }

    print_msg("Maximum value in the list: %i\n", max_val);

    // Task 4.3: Find the minimum value in the list
    uint32_t min_val = UINT_MAX;

    list_for_each_entry(__ptr, &int_list, lnode) {
        if (__ptr->val < min_val) {
            min_val = __ptr->val;
        }
    }

    print_msg("Minimum value in the list: %i\n", min_val);

    // Task 4.4: Divide all elements in the list by M = 25
    int M = 25;

    list_for_each_entry(__ptr, &int_list, lnode) {
        __ptr->val /= M;
    }

    print_msg("List after dividing by %i:\n", M);
    ilprint(&int_list);

    // Task 4.5: Shift all elements in the list to the left by 1 bit
    list_for_each_entry(__ptr, &int_list, lnode) {
        __ptr->val <<= 1;
    }

    print_msg("List after shifting left by 1 bit:\n");
    ilprint(&int_list);

    // Task 4.6: Shift all elements in the list to the right by 1 bit
    list_for_each_entry(__ptr, &int_list, lnode) {
        __ptr->val >>= 1;
    }

    print_msg("List after shifting right by 1 bit:\n");
    ilprint(&int_list);

    // Task 4.7: Invert all elements in the list
    list_for_each_entry(__ptr, &int_list, lnode) {
        __ptr->val = ~(__ptr->val);
    }

    print_msg("List after inverting elements:\n");
    ilprint(&int_list);

    return 0;

alloc_err:
    ilfree(&int_list);
    return ret;
}

static void __exit list_module_exit(void)
{
    ilfree(&int_list);
    print_msg("Hasta la vista, Kernel!\n");
}

module_init(list_module_init);
module_exit(list_module_exit);
