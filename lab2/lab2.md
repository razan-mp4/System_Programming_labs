# Тема: Створення статичних і динамічних бібліотек для POSIX сумісних (сертифікованих) операційних систем.
# Мета: Оволодіння практичними навичками розробки ПО на системному рівні з використанням бібліотек мови С (C++) для POSIX OS, на прикладі ОС Linux та автоматизації розробки з використанням Makefile статичних і динамічних бібліотек.

Завдання: <br />
> 1. Розробити консольний додаток у парадигмі ООП, що виконує наступні
> функції:
> - додавання “Робітника” до інформаційній системи або іншу інформаційну
> сутність за спрямованістю, що вказана у ЛР1 і за результатами ЛР1, далі
> просто “Робітника”;
> - видалення “Робітника” зі штату, при цьому він має залишатися у
> інформаційній системи, як минулий;
> - збільшення (зменшення) зарплатні “Робітника”, або іншу аналогічну
> інформаційну сутність за тематичною за спрямованістю, що вказана у ЛР1
> відповідно до варіанту;
> - зображення інформації про “Робітника”, або іншу аналогічну інформаційну
> сутність за тематичною за спрямованістю, що вказана у ЛР1 відповідно до
> варіанту.
> Для розробки скористатися вихідним кодом та інформацією, що вказана у [5].
> Реалізація вихідного коду показана у додатку 2.
> 2. Створити два репозиторія, користуючись інформацією [1]. У одному програма
> має бути розділена на основний коді і статичні бібліотеки. У іншому
> репозиторії розробити динамічні бібліотеки.
> 3. За бажанням можна реалізувати функціональність п.1 у чистому стилі ООП
> поза шаблоном [5] самостійно. Або реалізувати у процедурному варіанті.
> Результатом роботи мають бути 2 репозиторія. У першому 5 файлів вихідного коду
> відповідно додатку 1 і Makefile для створення динамічних бібліотек. У другому
> репозиторії 5 файлів вихідного коду відповідно додатку 1 і Makefile для
> створення статичних бібліотек.

№3: Інформаційна система таксопарку <br />
Клас <br />
Автомобілі (Код автомобіля, Код марки, Реєстраційний номер, Номер кузова, <br />
Номер двигуна, Рік випуску, Пробіг, Код шофѐра співробітника, Дата останнього ТО, <br />
Код-механіка співробітника, Спеціальні позначки) [10 записів]. <br />
Передбачити функціональність додавання інформації, вивід інформації на консоль. <br />
Передбачити функціональність поведінки класу, в залежності від значення певних <br />
членів класу. <br />
Під час тестування на етапі виконання створити екземпляри класу на купі пам'яті і <br />
на стеку. <br />
