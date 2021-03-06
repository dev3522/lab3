### Задание 3: Процессы и потоки. Межпроцессное и межпоточное взаимодействие. Способы синхронизации потоков и процессов, сигналы.
Написать следующую программу: в программе должно быть три процесса: A, B, C. Процесс A используется для непрерывного ввода данных от пользователя (число). Введенное пользователем число процесс A должен передать в процесс B используя механизм PIPE. Процесс B должен введенное число возвести в квадрат и используя механизм shared memory передать результат возведения в квадрат в процесс C. Процесс C должен состоять из двух потоков: поток C-1 и поток C-2, при этом поток C1 должен принимать от процесса B данные используя механизм Shared memory, поток C2 должен раз в секунду выводить произвольное сообщение на терминал (например “I am alive\n”), но в момент когда поток С1 принимает данные от процесса B - должен выводить на терминал сообщение “value = XXXX”, где XXXX - число переданное через механизм shared memory от процесса B (Результат возведения в степень числа введенного в процессе A). Если результат возведения в степень = “100” (т.е. пользователь ввел число 10), то программа должна послать сигнал SIGUSR1 процессу B, который в свою очередь в случае получения такого сигнала должен корректно завершить работу всех трех процессов (A,B,C).

### Требования к именам файлов:

 - Makefile - файл описывающий сборку
 - Названия файлов - произвольные.

### Сборка программы:

 - make - выполняет “make all”
 - make all - Собрать проект
 - make clean - удалить все что сгенерировано с помощью “make”/”make all"

### Требования к системе контроля версий:

 - Рабочий код должен быть в бранче "master"
 - Необходимо не менее 4 коммитов в git и залитые исходники на github

### Часто задаваемые вопросы и подсказки:

> Ознакомьтесь со стандартом POSIX в части необходимой для реализации программы. Код будет проверяться не только на фактическую работоспособность, но и на качество анализа возникающих ошибок, скорость работы и качество комментариев. Постарайтесь выбрать максимально быструю, понятную и простую реализацию с учетом требующейся архитектуры.
