#include <iostream>
#include <fstream>
#include "job.hpp"
using namespace std;

int main(int argc,char const *argv[])
{
if(argc==3)
{
	int Menu=0;
	Menu:
	cout << "1.Добавление \n2.Просмотр \n3.Вывод задач \n4.Присвоить задачу \n5.Удаление \n6.Выход \n";
	cin >> Menu;
	switch(Menu){
		case 1: 
			{
			int MenuAdd=0;
			cout << "1.Добавить работника \n2.Добавить задачу \n3.Вернуться \n";
			cin >> MenuAdd;
			switch(MenuAdd)
				{
				case 1:
				{
				Employees *E=new Employees[1];E->setAddE();break;
				}
				case 2:
				{
				Task *T=new Task[1];T->setAddT();break;
				}
				case 3:break;
				default:cout << "Ошибка выбора меню";break;
				}
			break;
			}
		case 2:
			{
                        int MenuView=0;
                        cout << "1.Просмотр работников \n2.Просмотр задач \n3.Вернуться \n";
                        cin >> MenuView;
                        switch(MenuView)
                                { 
                                case 1:break;
                                case 2:break;
				case 3:break;
                                default:cout << "Ошибка выбора меню";break; 
                                }
                        break; 
                        }
		case 3:break;
		case 4:break;
		case 5:
			{
                        int MenuDelete=0;
                        cout << "1.Удалить работник \n2.Удалить задачу \n3.Вернуться \n";
                        cin >> MenuDelete;
                        switch(MenuDelete)
                                { 
                                case 1:break;
                                case 2:break;
				case 3:break;
                                default:cout << "Ошибка выбора меню";break; 
                                }
                        break; 
                        }
		case 6:return 0;
		default:cout << "Ошибка выбора меню";break;
	}
goto Menu;
}
}
