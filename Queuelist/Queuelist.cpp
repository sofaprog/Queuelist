// Main function
//meow
/*/\_/\
 ( o.o )
  > ^ <*/
#include <iostream>
#include "Queuelist.h"
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    Queue<int> q1;
    system("chcp 1251");
    double p = 0.0;
    double q = 0.0;
    std::cout << "Введите вероятность добавления задачи P (0, 100): "; std::cin >> p;
    std::cout << std::endl << "Введите вероятность извлечения задачи Q (0, 100): "; std::cin >> q;

    int countPushSuccess = 0;
    int countPopSuccess = 0;
    int countPushExcept = 0;
    int countPopExcept = 0;

    for (int i = 0; i < 100; i++) {
        int randNumPush = rand() % 100;
        if (randNumPush < p) {
            try {
                q1.enqueue(i);
                countPushSuccess++;
                std::cout << randNumPush << " < " << p << ", добавить " << i << std::endl;
            }

            catch (...) {
                countPushExcept++;
                std::cout << "Очередь полна, не могу добавить" << std::endl;
            }
        }

        int randNumPop = rand() % 100;
        int tmp = 0;
        if (randNumPop < q)
            try {
            tmp = q1.peektail();
            countPopSuccess++;
            std::cout << randNumPop << " < " << q << " изъять " << tmp << std::endl;
        }
        catch (...) {
            countPopExcept++;
            std::cout << "Очередь пуста, не могу изъять" << std::endl;
        }
    }

    std::cout << "countPushSuccess = " << countPushSuccess << std::endl;
    std::cout << "countPopSuccess = " << countPopSuccess << std::endl;
    std::cout << "countPushExcept = " << countPushExcept << std::endl;
    std::cout << "countPopExcept = " << countPopExcept << std::endl;

}