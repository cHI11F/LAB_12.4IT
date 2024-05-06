#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_12.4/LAB_12.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestContainsAdjacentDuplicates)
        {
            // Arrange
            int values[] = { 1, 2, 2, 3, 4, 5, 5, 6, 7 };
            int size = sizeof(values) / sizeof(values[0]);
            Node* head = createList(values, size);

            // Act
            bool result = containsAdjacentDuplicates(head);

            // Assert
            Assert::IsTrue(result);
            deleteList(head); // Звільнення пам'яті після виконання тесту
        }

        TEST_METHOD(TestDoesNotContainAdjacentDuplicates)
        {
            // Arrange
            int values[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            int size = sizeof(values) / sizeof(values[0]);
            Node* head = createList(values, size);

            // Act
            bool result = containsAdjacentDuplicates(head);

            // Assert
            Assert::IsFalse(result);
            deleteList(head); // Звільнення пам'яті після виконання тесту
        }
    };
}
