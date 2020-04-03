#include <iostream>
#include <random>

void Task1()
{
    system("cls");
    setlocale(LC_ALL, "rus");

    std::string ranger;
    std::string planet;
    std::string star;
    int money;

    std::cout << "Вводите название планеты: ";
    std::cin >> planet;
    std::cout << "Вводите название звездной системы: ";
    std::cin >> star;
    std::cout << "Вводите имя рейнджера: ";
    std::cin >> ranger;
    std::cout << "Введите величину вознаграждения: ";
    std::cin >> money;

    std::cout << std::endl;
    std::cout << "===========================================================================================================" << std::endl;
    std::cout << "Как вам " << ranger << ", известно, мы - раса мирная, поэтому на наших военных " << std::endl;
    std::cout << "кораблях используются наемники с других планет. Система набора отработана " << std::endl;
    std::cout << "давным-давно. Обычно мы приглашаем на наши корабли людей с планеты " << planet << " системы " << star << "." << std::endl;
    std::cout << std::endl;

    std::cout << "Но случилась неприятность - в связи с большими потерями в последнее время " << std::endl;
    std::cout << "престиж профессии сильно упал, и теперь не так-то просто завербовать " << std::endl;
    std::cout << "призывников. Главный комиссар планеты " << planet << ", впрочем, отлично справлялся, " << std::endl;
    std::cout << "но недавно его наградили орденом Сутулого с закруткой на спине, и его на " << std::endl;
    std::cout << "радостях парализовало! Призыв под угрозой срыва!" << std::endl;
    std::cout << std::endl;

    std::cout << ranger << ", вы должны прибыть на планету " << planet << " системы " << star << " и помочь " << std::endl;
    std::cout << "выполнить план призыва. Мы готовы выплатить вам премию в " << money << " кредитов за эту маленькую услугу." << std::endl;
    std::cout << "==========================================================================================================" << std::endl;
    std::cout << std::endl;
}

void Task2()
{
    system("cls");
    setlocale(LC_ALL, "rus");

    // количество остановок на маршруте
    const int N = 4;  

    // максимальное количество пассажиров вмещаемых в автобусе
    const int maxPassengers = 15;

    // количество пассажиров в салоне автобуса
    int numberOfPassengers = 0;

    // количество пассажиров зашедших на остановке в автобус
    int inPassengers = 0;

    // количество пассажиров вышедших на остановке из автобуса
    int outPassengers = 0;         

    // Название остановок на маршруте автобуса
    std::string station[N] = { "Улица Программистов",
                               "Проспект Алгоритмов", 
                               "Улица Дональда Кнута", 
                               "Проспект Ломоносова" }; 

    // Цена билета
    int ticketPrice = 20; 

    // Суммарный доход
    int totalIncome = 0;

    // Зарплата водителя
    int driverSalary = 0;

    // Расходы на топливо
    int fuelCosts = 0;

    // Налоги
    int taxes = 0;

    // Расходы на ремонт машины
    int repairCosts = 0;

    // Доход
    int result;

    // Генерируем случайное число
    std::random_device rd;

    // Инициализируем Вихрь Мерсенна случайным стартовым числом 
    std::mt19937 mersenne(rd());


    for (int i = 0; i < N; i++)
    {
        if (i != N - 1)
        {
            std::cout << "Прибываем на остановку: " << station[i] << std::endl;
        }
        else
        {
            std::cout << "Прибываем на остановку: " << station[i] << "; Конечная, всем выйти из автобуса!" << std::endl;
        }
                
        std::cout << "В салоне пассажиров: " << numberOfPassengers << std::endl;

        if (i != 0 && i != N - 1)
        {
            outPassengers = mersenne() % 10;

            if (0 < numberOfPassengers)
            {
                if (numberOfPassengers - outPassengers > 0)
                {
                    numberOfPassengers -= outPassengers;
                    std::cout << "Пассажиров вышло на остановке: " << outPassengers << std::endl;
                }
                else
                {
                    std::cout << "Пассажиров вышло на остановке: " << numberOfPassengers << std::endl;
                    numberOfPassengers = 0;                    
                }                
            }
        }

        if (i == N - 1)
        {
            if (numberOfPassengers != 0)
            {
                std::cout << "Пассажиров вышло на остановке: " << numberOfPassengers << std::endl;
                numberOfPassengers = 0;
            }
        }

        if (i != N - 1)
        {
            inPassengers = mersenne() % 10;

            if (numberOfPassengers <= maxPassengers)
            {
                if (numberOfPassengers + inPassengers <= maxPassengers)
                {
                    std::cout << "Пассажиров вошло на остановке: " << inPassengers << std::endl;
                    numberOfPassengers += inPassengers;
                    totalIncome += ticketPrice * inPassengers;
                }
                else
                {
                    std::cout << "Пассажиров вошло на остановке: " << maxPassengers - inPassengers << std::endl;
                    numberOfPassengers += maxPassengers - inPassengers;
                    totalIncome += maxPassengers - inPassengers;
                }                
            }
        }        

        if (i != N - 1)
        {
            std::cout << "Отправляемся с остановки: " << station[i] << std::endl;
            std::cout << "Количество пассажиров в салоне автобуса: " << numberOfPassengers << std::endl;
            std::cout << "Следующая остановка: " << station[i + 1] << std::endl;
            std::cout << "=================================================================================================" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "===============Расходы и Доходы===========================" << std::endl;

    driverSalary = totalIncome / 4;
    fuelCosts = totalIncome / 5;
    taxes = totalIncome / 5;
    repairCosts = totalIncome / 5;
    result = totalIncome - driverSalary - fuelCosts - taxes - repairCosts;

    std::cout << "Всего заработали: " << totalIncome << std::endl;
    std::cout << "Зарплата водителя: " << driverSalary << std::endl;
    std::cout << "Расходы на топливо: " << fuelCosts << std::endl;
    std::cout << "Налоги:" << taxes << std::endl;
    std::cout << "Расходы на ремонт машины: " << repairCosts << std::endl;
    std::cout << "Итого доход: " << result << std::endl;
}

void Task3()
{
    int a = 42;
    int b = 153;
    int temp = 0;

    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";
    std::cout << std::endl;

    temp = a;
    a = b;
    b = temp;

    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";
    std::cout << std::endl;
}

void Task4()
{
    system("cls");
    setlocale(LC_ALL, "rus");

    //===============================================Часть 1=========================================================

    // Длина бамбука
    int bambooLength = 100;

    // номер дня
    int N = 3;

    // Целевая длина бамбука
    int maxBambooLength = 300;

    // Ежесуточный прирост
    int dailyGain = 50;

    // Ежесуточное снижение
    int dailyDecrease = 20;

    // Длина бамбука в середине произвольного дня
    int length = 0;

    // Количество дней раста бамбука
    int days = 0;

    std::cout << "Начальная длина бамбука: " << bambooLength << std::endl;
    std::cout << "Целевая длина бамбука: " << maxBambooLength << std::endl;
    std::cout << "Ежесуточный прирост бамбука: " << dailyGain << std::endl;
    std::cout << "Скорость поедания бамбука гусеницами: " << dailyDecrease << std::endl;
    std::cout << "Номер дня в середине которого необходимо найти высоту бамбука: " << N << std::endl;
    std::cout << std::endl;

    length = bambooLength + (dailyGain - dailyDecrease) * N - (10 / 18) * dailyGain;    
    days = (maxBambooLength - bambooLength) / (dailyGain - dailyDecrease) + 1;
       
    std::cout << "Количество полных дней которые потребуются для достижения высоты " << maxBambooLength << ": " << days << std::endl;
    std::cout << "Высота бамбука в середине " << N << " дня: " << length << std::endl;
    std::cout << std::endl;

    //============================================Часть 2==============================================================

    std::cout << "Введите начальну длину бамбука: ";
    std::cin >> bambooLength;
    std::cout << "Введите целевую длину бамбука: ";
    std::cin >> maxBambooLength;
    std::cout << "Введите ежесуточный прирост бамбука: ";
    std::cin >> dailyGain;
    std::cout << "Введите скорость поедания бамбука гусеницами: ";
    std::cin >> dailyDecrease;
    std::cout << "Введите номер дня в середине которого необходимо найти высоту бамбука: ";
    std::cin >> N;
    std::cout << std::endl;

    if (bambooLength >=0 && maxBambooLength > 0 && dailyGain > 0 && dailyDecrease >= 0 && N > 0)
    {
        if (maxBambooLength > bambooLength)
        {
            if (dailyGain > dailyDecrease)
            {
                days = (maxBambooLength - bambooLength) / (dailyGain - dailyDecrease) + 1;
                length = bambooLength + (dailyGain - dailyDecrease) * N - (10 / 18) * dailyGain;

                std::cout << "Количество полных дней которые потребуются для достижения высоты " << maxBambooLength << ": " << days << std::endl;
                std::cout << "Высота бамбука в середине " << N << " дня: " << length << std::endl;
            }

            if (dailyGain == dailyDecrease)
            {
                std::cout << "Высота бамбука не меняется!!!" << std::endl;
            }

            if (dailyGain < dailyDecrease)
            {
                days = bambooLength / (dailyDecrease - dailyGain) + 1;
                std::cout << "Целевой длины достичь невозможно !!!" << std::endl;
                std::cout << "Гусеницы съедят весь бамбук через: " << days << std::endl;
                
                if (N < days)
                {
                    length = bambooLength + (dailyGain - dailyDecrease) * N + (10 / 18) * dailyGain;
                    std::cout << "Высота бамбука в середине " << N << " дня: " << length << std::endl;
                }
            }
        }
        else
        {
            std::cout << "Целевая длина бамбука неможет быть меньше или равна начальной!!!" << std::endl;
        }
    }
    else
    {
        std::cout << "Некорректно введённые данные!!!" << std::endl;
    }
}

void Task5()
{
    int a = 3400;
    int b = 15;
    
    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";
    std::cout << std::endl;

    a = a + b;
    b = a - b;
    a = a - b;

    std::cout << "a: " << a << "\n";
    std::cout << "b: " << b << "\n";
    std::cout << std::endl;
}

int main()
{
    //Task1();
    //Task2();
    //Task3();
    //Task4();
    Task5();
}
