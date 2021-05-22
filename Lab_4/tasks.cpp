#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void task1()
{
    deque<string> first;
    deque<string> second;
    string text;
    cout << "task1 begin" << endl<<endl;
    ifstream file("/home/msi/Рабочий стол/Lab_4/Lab4/task1");
    if (file.is_open())
    {
        while (getline(file, text))
        {
            if (first.isEmpty())
                first.push_back(text); //первая книга всегда кладется в первый дек
            else
                second.push_back(text); //остальные идут во второй

            if (second.end() >= first.end()) //сортировка книг
            {
                first.push_back(second.end());
                second.pop_back();
            }
            else //если нашли то, что надо положить в середину или начало
            {
                while (!first.isEmpty() && second.end() < first.end()) //перекладываем в начало второго дека, пока не найдем нужную позицию
                {
                    second.push_front(first.end());
                    first.pop_back();
                }
                first.push_back(second.end());
                second.pop_back();
                while (!second.isEmpty()) //возвращаем книги обратно в первый дек
                {
                    first.push_back(second.begin());
                    second.pop_front();
                }
            }
        }
    }
    file.close();

    cout<<"Книги по алфавиту"<<endl<<endl;

    while (!first.isEmpty())
    {
        cout << first.begin() << endl;
        first.pop_front();
    }
    cout<<endl<<"task1 end"<<endl<<endl;
}

void task2()
{
    deque<char> st;
    cout<<"task2 begin"<<endl<<endl;
    string text;
    ifstream file("/home/msi/Рабочий стол/Lab_4/Lab4/task2");

    if (file.is_open())
    {
        while (getline(file, text))
        {
            cout<<"Зашифрованное сообщение: "<<text<<endl;
            for (char i : text)
            {
                st.push_back(i);
            }
        }
    }
    file.close();



    st.push_front(st.end());
    st.pop_back();

    st.push_front(st.end());
    st.pop_back();

    cout<<"Расщифрованное сообщение: ";

    while(!st.isEmpty())
    {
        cout << st.begin();
        st.pop_front();
    }
    cout<<endl;
    cout<<endl<<"task2 end"<<endl<<endl;

}


void hanoi(int n, stack<string> &start, stack<string> &middle, stack<string> &end)
{
    if (n==1)
    {
        end.push_back(start.end());
        start.pop_back();
    }
    else
    {
        hanoi(n-1, start, end, middle);
        end.push_back(start.end());
        start.pop_back();
        hanoi(n-1,middle, start, end);
    }
}

void task3()
{
    cout << "task3 begin" << endl << endl;
    string text;

    stack<string> first;
    stack<string> second;
    stack<string> third;


    ifstream file("/home/msi/Рабочий стол/Lab_4/Lab4/task3");


    if (file.is_open())
    {
        while (getline(file, text))
        {
            first.push_back(text);
        }
    }
    file.close();

    hanoi(first.size(), first, second,third);

    while(!third.isEmpty())
    {
        cout<<third.end()<<" ";
        third.pop_back();
    }

    cout << endl << "task3 end" << endl << endl;

}

void task4()
{
    stack<char> st;
    cout<<"task4 begin"<<endl<<endl;
    string text;
    int cnt=0;
    cout<<"Положительное число-перебор открытых скобок, отрицательное- закрытых, 0- баланс"<<endl;

    ifstream file("/home/msi/Рабочий стол/Lab_4/Lab4/task4");

    if(file.is_open())
    {
        while (getline(file, text))
        {
            for (char i : text)
            {
                st.push_back(i);
            }
        }
    }
    file.close();

    while(!st.isEmpty())
    {
        if (st.end()=='(')
            cnt++;
        else if (st.end()==')')
            cnt--;
        st.pop_back();
    }

    cout<<cnt<<endl;

    cout<<endl<<"task4 end" <<endl;
}

void task5()
{
    deque<char> st;
    cout<<"task5 begin"<<endl<<endl;
    string text;
    int cnt=0;
    cout<<"Положительное число-перебор открытых скобок, отрицательное- закрытых, 0- баланс"<<endl;

    ifstream file("/home/msi/Рабочий стол/Lab_4/Lab4/task5");

    if(file.is_open())
    {
        while (getline(file, text))
        {
            for (char i : text)
            {
                st.push_back(i);
            }
        }
    }
    file.close();

    while(!st.isEmpty())
    {
        if (st.end()=='[')
            cnt++;
        else if (st.end()==']')
            cnt--;
        st.pop_back();
    }

    cout<<cnt<<endl;

    cout<<endl<<"task5 end" <<endl;
}

void task6()
{
    cout<< "task6 begin"<<endl<<endl;

    stack<char> templetters;
    stack<char> letters;
    stack<char> tempnumbers;
    stack<char> numbers;
    stack<char> tempothers;
    stack<char> others;

    string text;
    cout<<"Положительное число-перебор открытых скобок, отрицательное- закрытых, 0- баланс"<<endl;

    ifstream file("/home/msi/Рабочий стол/Lab_4/Lab4/task6");

    if(file.is_open())
    {
        while (getline(file, text))
        {
            for (char i : text)
            {
                if (isdigit(i))
                {
                    tempnumbers.push_back(i);
                }
                else if (isalpha(i))
                {
                    templetters.push_back(i);
                }
                else
                {
                    tempothers.push_back(i);
                }
            }
        }
    }
    file.close();

    while(!tempnumbers.isEmpty())
    {
        numbers.push_back(tempnumbers.end());
        tempnumbers.pop_back();
    }
    while(!templetters.isEmpty())

    {
        letters.push_back(templetters.end());
        templetters.pop_back();
    }

    while(!tempothers.isEmpty())
    {
        others.push_back(tempothers.end());
        tempothers.pop_back();
    }

    while (!numbers.isEmpty())
    {
        cout << numbers.end();
        numbers.pop_back();
    }

    while (!letters.isEmpty())
    {
        cout << letters.end();
        letters.pop_back();
    }

    while (!others.isEmpty())
    {
        cout << others.end();
        others.pop_back();
    }

    cout<<endl<<endl<<"task6 end"<<endl;
}

void task7()
{
    cout<<endl<< "task7 begin" << endl<<endl;

    stringstream ss;
    string text;
    string temp;
    int found;
    deque<int> positive;
    deque<int> negative;

    ifstream file ("/home/msi/Рабочий стол/Lab_4/Lab4/task7");

    if (file.is_open())
    {
        while(getline(file, text))
        {
            ss <<text;

            while (!ss.eof())
            {
                ss>>temp;

                if (stringstream(temp) >> found)
                {
                    (found<0)? negative.push_back(found) : positive.push_back(found);
                }
                temp="";
            }
        }
    }
    file.close();

    while(!negative.isEmpty())
    {
        cout<<negative.begin()<< " ";
        negative.pop_front();
    }

    while(!positive.isEmpty())
    {
        cout<<positive.begin()<< " ";
        positive.pop_front();
    }

    cout<<endl<<endl<<"task7 end"<<endl;
}

void task8()
{
    cout << endl << "task8 begin" << endl << endl;

    string text;
    stack<string> strings;

    ifstream file("/home/msi/Рабочий стол/Lab_4/Lab4/task8");

    if (file.is_open())
    {
        while (getline(file, text))
        {
            strings.push_back(text);
        }
    }
    file.close();

    ofstream fileout;

    fileout.open("/home/msi/Рабочий стол/Lab_4/Lab4/task8output.txt");

    if (fileout.is_open())
    {
        while (!strings.isEmpty())
        {
            fileout << strings.end() << endl;
            strings.pop_back();

        }
    }
    cout << endl << endl << "task8 end" << endl;
}