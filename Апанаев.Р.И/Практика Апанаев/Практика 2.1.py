a=float (input ('Введите первое число '))#вводные данные делаем типа инт
b=float (input ('Введите второе число '))
o=input ('Какую операцию будем выполнять? + - * /')
if o=='+' :  
    c=a+b
    print(c)
elif o=='-' :  # если нет то это условие
    c=a-b
    print(c)
elif o=='*' :
    c=a*b
    print(c)
elif (o=='/' and b==0) :
    print('Нельзя так')
elif o=='/' :
    c=a/b 
    print(c)
else: print('Вы ввели не верную операцию')  # если вообще нет то 