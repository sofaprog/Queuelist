//meow
/*/\_/\
 ( o.o )
  > ^ <*/
#include "pch.h"
#include "../Queuelist/Queuelist.h"
TEST(Queue, Correct_IsEmpty_Initially) {
    Queue<int> q1;
    bool f = q1.isEmpty();
    EXPECT_EQ(true, f); // Очередь должна быть пустой сразу после создания
}
TEST(Queue, Correct_IsEmpty_AfterPush) {
    Queue<int> q1;
    q1.enqueue(1);
    bool f = q1.isEmpty();
    EXPECT_EQ(0, f); // Очередь не должна быть пустой после добавления элемента
}
TEST(Queue, Correct_Push) {
    Queue<int> q1;
    q1.enqueue(42);
    EXPECT_EQ(42, q1.peektail()); // Проверяем, что элемент добавлен в конец
}
TEST(Queue, Correct_Pop) {
    Queue<int> q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.dequeue();
    q1.dequeue();
    EXPECT_EQ(30, q1.peektail()); // Проверяем, что pop удаляет правильное значение
}
TEST(Queue, Correct_PopPush) {
    Queue<int> q1;
    q1.enqueue(10);
    EXPECT_EQ(10, q1.peektail());
    q1.enqueue(20);
    q1.dequeue();
    EXPECT_EQ(20, q1.peekhead());
    q1.enqueue(30);
    q1.enqueue(40);
    EXPECT_EQ(40, q1.peektail());
    EXPECT_EQ(20, q1.peekhead());
}
TEST(Queue, Correct_PeekHead) {
    Queue<int> q1;
    q1.enqueue(0);
    for (int i = 1; i < 5; i++) {
        q1.enqueue(i);
        EXPECT_EQ(0, q1.peekhead()); // Голова очереди не меняется
    }
}
TEST(Queue, Correct_PeekTail) {
    Queue<int> q1;
    for (int i = 0; i < 5; i++) {
        q1.enqueue(i);
        EXPECT_EQ(i, q1.peektail()); // Хвост должен совпадать с последним добавленным элементом
    }
}
TEST (Queue, Correct_Equal_True) {
    Queue<int> q1, q2;
    for (int i = 0; i < 5; i++) {
        q1.enqueue(i);
        q2.enqueue(i);
    }
    EXPECT_EQ(q1==q2,true); // Две одинаковые очереди должны быть равны
}

TEST(Queue, Correct_Equal_False) {
    Queue<int> q1, q2;
    for (int i = 0; i < 5; i++) {
        q1.enqueue(i);
        q2.enqueue(i);
    }
    q1.dequeue();
    EXPECT_NE(q1, q2); // Очереди с разными элементами должны быть не равны
}
TEST(Queue, Correct_Assignment_Copy) {
    Queue<int> q1, q2;
    for (int i = 0; i < 5; i++) {
        q1.enqueue(i);
    }
    q2 = q1;
    EXPECT_EQ(q1, q2); // Проверяем, что после присваивания очереди равны
}

TEST(Queue, Correct_Assignment_Independent) {
    Queue<int> q1, q2;
    for (int i = 0; i < 5; i++) {
        q1.enqueue(i);
    }
    q2 = q1;
    q1.dequeue();
    EXPECT_NE(q1, q2); // Проверяем, что очереди независимы после присваивания
}
TEST(Queue, TestPeekOnEmptyQueue) {
    Queue<int> queue;
    EXPECT_THROW(queue.peekhead(), int);
    EXPECT_THROW(queue.peektail(), int);
}
TEST(Queue, TestDequeueOnemptyQueue) {
    Queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    q.dequeue();
    EXPECT_ANY_THROW(q.dequeue());
}


