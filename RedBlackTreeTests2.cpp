
#include <iostream>
#include <cassert>
#include <random>
#include "RedBlackTree.h"

using namespace std;

void TestSimpleConstructor()
{
	cout << "Testing Simple Constructor... " << endl;
	RedBlackTree rbt = RedBlackTree();
	// cout << "empty r-b-tree: " << rbt->ToInfixString() << endl;
	assert(rbt.ToInfixString() == "");

	cout << "PASSED!" << endl
		 << endl;
}

void TestInsertFirstNode()
{
	cout << "Testing Insert One Node..." << endl;
	RedBlackTree rbt = RedBlackTree();
	rbt.Insert(30);
	// cout << "rbt: " << rbt->ToPrefixString() << endl;
	assert(rbt.ToPrefixString() == " B30 ");

	cout << "PASSED!" << endl
		 << endl;
}

void TestInsertSecondNode()
{
	cout << "Testing Insert Second Node..." << endl;
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(30); // leak here
	rbt->Insert(15);
	assert(rbt->ToPrefixString() == " B30  R15 ");
	delete rbt;

	rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(45);
	assert(rbt->ToPrefixString() == " B30  R45 ");
	delete rbt;

	cout << "PASSED!" << endl
		 << endl;
}

void TestInsertThirdNode()
{
	cout << "Testing Insert Third Node..." << endl;
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(15);
	rbt->Insert(10); // Left Left
	// cout << "rbt: "  << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B15  R10  R30 ");
	delete rbt;

	rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(15);
	rbt->Insert(25); // Right Left
	assert(rbt->ToPrefixString() == " B25  R15  R30 ");
	delete rbt;

	rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(15);
	rbt->Insert(45); // Easy case
	assert(rbt->ToPrefixString() == " B30  R15  R45 ");
	delete rbt;

	// more tests go here
	// consider some symmetry!

	cout << "TESTS MISSING" << endl
		 << endl;
	cout << "PASSED!" << endl
		 << endl;
}

void TestInsertFourthNode()
{
	cout << "Testing Insert Fourth Node..." << endl;

	cout << "TESTS MISSING" << endl
		 << endl;

	cout << "PASSED!" << endl
		 << endl;
}

void TestInsertFifthNode()
{
	cout << "Testing Insert Fifth Node..." << endl;
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(15);
	rbt->Insert(45);
	rbt->Insert(10);
	rbt->Insert(25);
	// cout << "result: "  << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B30  B15  R10  R25  B45 ");
	delete rbt;

	cout << "TESTS MISSING" << endl
		 << endl;

	cout << "PASSED!" << endl
		 << endl;
}

void TestRemove()
{
	cout << "Testing Remove Node..." << endl;
	RedBlackTree *rbt = new RedBlackTree();

	rbt = new RedBlackTree();
	rbt->Insert(40);
	rbt->Insert(20);
	rbt->Insert(80);
	rbt->Insert(10);
	rbt->Insert(30);
	rbt->Insert(60);
	rbt->Insert(100);
	rbt->Insert(5);
	rbt->Insert(15);
	rbt->Insert(25);
	rbt->Insert(35);
	rbt->Insert(50);
	rbt->Insert(70);
	rbt->Insert(90);
	rbt->Insert(26);
 
	assert(rbt->ToPrefixString() == " B40  B20  B10  R5  R15  R30  B25  R26  B35  B80  B60  R50  R70  B100  R90 ");

	rbt->Remove(20);
	assert(rbt->ToPrefixString() == " B40  B25  B10  R5  R15  R30  B26  B35  B80  B60  R50  R70  B100  R90 ");


 rbt = new RedBlackTree(); 
	rbt = new RedBlackTree();
	rbt->Insert(15);
	rbt->Insert(10);
	rbt->Insert(1);
	rbt->Insert(20);
	rbt->Insert(19);
	rbt->Insert(16);

	rbt->Remove(20); 
	assert(rbt->ToInfixString() == " B1  B10  B15  R16  B19 ");
 

rbt = new RedBlackTree(); 
	rbt->Insert(15);
	rbt->Insert(10);
	rbt->Insert(1);
	rbt->Insert(20);
	rbt->Insert(19);
	rbt->Insert(16); 
	rbt->Remove(1);
 
	assert(rbt->ToInfixString() == " B10  R15  B16  B19  B20 ");



	rbt = new RedBlackTree();
	rbt->Insert(15);
	rbt->Insert(100);
	rbt->Insert(10);
	rbt->Insert(11);
	rbt->Insert(7);
	rbt->Insert(12);

	rbt->Remove(100);
	// cout << "after: " << rbt->ToInfixString();
	assert(rbt->ToInfixString() == " B7  B10  B11  R12  B15 ");


	rbt = new RedBlackTree();
	rbt->Insert(9);
	rbt->Insert(5);
	rbt->Insert(11);
	rbt->Insert(2);
	rbt->Insert(7);
	rbt->Insert(10);
	rbt->Insert(14);
	rbt->Insert(6);

	rbt->Remove(2);
	// cout << "after: " << rbt->ToInfixString();
	assert(rbt->ToInfixString() == " B5  R6  B7  B9  R10  B11  R14 ");

	rbt = new RedBlackTree();
	rbt->Insert(15);
	rbt->Insert(10);
	rbt->Insert(20);
	rbt->Insert(23);

	rbt->Remove(20);
	// cout << "after: " << rbt->ToInfixString();
	assert(rbt->ToInfixString() == " B10  B15  B23 ");

	rbt = new RedBlackTree();
	rbt->Insert(15);
	rbt->Insert(10);
	rbt->Insert(20);
	rbt->Insert(23);

	rbt->Remove(10);
	// cout << "after: " << rbt->ToInfixString();
	assert(rbt->ToInfixString() == " B15  B20  B23 ");

	rbt = new RedBlackTree();
	rbt->Insert(15);
	rbt->Insert(10);
	rbt->Insert(20);
	rbt->Insert(19);

	rbt->Remove(10);
	// cout << "after: " << rbt->ToInfixString();
	assert(rbt->ToInfixString() == " B15  B19  B20 ");

	rbt = new RedBlackTree();
	rbt->Insert(15);
	rbt->Insert(10);
	rbt->Insert(20);
	rbt->Insert(21);

	rbt->Remove(10);
	// cout << "after: " << rbt->ToInfixString();
	assert(rbt->ToInfixString() == " B15  B20  B21 ");

	rbt = new RedBlackTree();
	rbt->Insert(15);
	rbt->Insert(10);
	rbt->Insert(20);
	rbt->Insert(2);

	rbt->Remove(20);
	// cout << "after: " << rbt->ToInfixString();
	assert(rbt->ToInfixString() == " B2  B10  B15 ");

	rbt = new RedBlackTree();
	rbt->Insert(15);
	rbt->Insert(10);
	rbt->Insert(20);
	rbt->Insert(11);

	rbt->Remove(20);
	assert(rbt->ToInfixString() == " B10  B11  B15 ");

	rbt = new RedBlackTree();
	rbt->Insert(50);
	rbt->Insert(30);
	rbt->Insert(70);
	rbt->Insert(60);
	rbt->Insert(80);
	rbt->Insert(55);

	rbt->Remove(55);
	assert(rbt->ToInfixString() == " B30  B50  B60  R70  B80 ");
	rbt->Remove(30);
	assert(rbt->ToInfixString() == " B50  R60  B70  B80 ");

	rbt = new RedBlackTree();
	rbt->Insert(70);
	rbt->Insert(60);
	rbt->Insert(80);
	rbt->Insert(75);
	rbt->Insert(85);
	rbt->Insert(55);

	rbt->Remove(55);
	assert(rbt->ToInfixString() == " B60  B70  R75  B80  R85 ");
	rbt->Remove(60);
	assert(rbt->ToInfixString() == " B70  R75  B80  B85 ");

	rbt = new RedBlackTree();
	rbt->Insert(50);
	rbt->Insert(30);
	rbt->Insert(70);
	rbt->Insert(20);
	rbt->Insert(40);
	rbt->Insert(45);

	rbt->Remove(45);
	assert(rbt->ToPrefixString() == " B50  R30  B20  B40  B70 ");
	rbt->Remove(70);
	assert(rbt->ToPrefixString() == " B30  B20  B50  R40 ");

	rbt = new RedBlackTree();
	rbt->Insert(60);
	rbt->Insert(80);
	rbt->Insert(50);
	rbt->Insert(10);
	rbt->Insert(55);
	rbt->Insert(56);

	rbt->Remove(56);
	assert(rbt->ToInfixString() == " B10  R50  B55  B60  B80 ");
	rbt->Remove(80);
	assert(rbt->ToInfixString() == " B10  B50  R55  B60 ");

	rbt = new RedBlackTree();
	rbt->Insert(50);
	rbt->Insert(30);
	rbt->Insert(70);
	rbt->Insert(60);
	rbt->Insert(80);
	rbt->Insert(55);
	rbt->Remove(55);
	assert(rbt->ToPrefixString() == " B50  B30  R70  B60  B80 ");

	rbt->Remove(30);
	assert(rbt->ToPrefixString() == " B70  B50  R60  B80 ");
	// delete rbt;

	rbt = new RedBlackTree();
	rbt->Insert(50);
	rbt->Insert(30);
	rbt->Insert(70);
	rbt->Insert(20);
	rbt->Insert(40);
	rbt->Insert(45);
	rbt->Remove(45);
	assert(rbt->ToPrefixString() == " B50  R30  B20  B40  B70 ");

	rbt->Remove(70);
	assert(rbt->ToPrefixString() == " B30  B20  B50  R40 ");

	delete rbt;
	cout << "PASSED!" << endl
		 << endl;
}

void TestToStrings()
{
	cout << "Testing ToString Methods..." << endl;

	RedBlackTree rbt = RedBlackTree();
	rbt.Insert(12);
	rbt.Insert(11);
	rbt.Insert(15);
	rbt.Insert(5);
	rbt.Insert(13);
	rbt.Insert(7);

	assert(rbt.ToPrefixString() == " B12  B7  R5  R11  B15  R13 ");
	assert(rbt.ToInfixString() == " R5  B7  R11  B12  R13  B15 ");
	assert(rbt.ToPostfixString() == " R5  R11  B7  R13  B15  B12 ");

	cout << "PASSED!" << endl
		 << endl;
}

void TestInsertRandomTests()
{
	cout << "Testing Random Insert Stuff..." << endl;
	cout << "\t This test passes if it doesn't crash and valgrind reports no issues" << endl;
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(15);
	rbt->Insert(13);
	rbt->Insert(20);
	rbt->Insert(12);
	cout << endl;
	// cout << "tree: " << rbt->ToInfixString() << endl;
	delete rbt;

	// probably should have a delete or something here
	rbt = new RedBlackTree();
	// cout << endl << "NEW TREE" << endl;
	rbt->Insert(12);
	// cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(11);
	// cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(15);
	// cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(5);
	// cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(13);
	// cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(7);
	// cout << "tree: "  << rbt->ToInfixString() << endl;
	delete rbt;

	rbt = new RedBlackTree();
	// cout << endl << "NEW TREE" << endl;
	rbt->Insert(12);
	// cout << "tree: "  << rbt->ToPrefixString() << endl;
	rbt->Insert(10);
	// cout << "tree: "  << rbt->ToPrefixString() << endl;
	rbt->Insert(8);
	// cout << "tree: "  << rbt->ToPrefixString() << endl;
	delete rbt;

	cout << "PASSED!" << endl
		 << endl;
}

void TestCopyConstructor()
{
	cout << "Testing Copy Constructor..." << endl;

	RedBlackTree rbt1 = RedBlackTree();
	rbt1.Insert(11);
	rbt1.Insert(23);
	rbt1.Insert(9);
	rbt1.Insert(52);
	rbt1.Insert(31);
	rbt1.Insert(4);

	assert(rbt1.ToPrefixString() == " B11  B9  R4  B31  R23  R52 ");

	RedBlackTree rbt2 = RedBlackTree(rbt1);

	assert(rbt2.ToPrefixString() == rbt1.ToPrefixString());

	rbt1.Insert(200);
	assert(rbt2.ToPrefixString() != rbt1.ToPrefixString());

	cout << "PASSED!" << endl
		 << endl;
}

void TestContains()
{
	cout << "Testing Contains..." << endl;
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(40);
	rbt->Insert(22);
	rbt->Insert(15);
	rbt->Insert(31);
	rbt->Insert(55);
	rbt->Insert(12);
	rbt->Insert(17);
	rbt->Insert(29);
	rbt->Insert(34);

	assert(rbt->Contains(34));
	delete rbt;

	cout << "TESTS MISSING" << endl
		 << endl;
	cout << "PASSED!" << endl
		 << endl;
}

void TestGetMinimumMaximum()
{
	cout << "Testing Get Minimum and Get Maximum..." << endl;

	cout << "TESTS MISSING" << endl
		 << endl;

	cout << "PASSED!" << endl
		 << endl;
}

int main()
{

	TestSimpleConstructor();

	TestInsertFirstNode();
	TestInsertSecondNode();
	TestInsertThirdNode();
	TestInsertFourthNode();
	TestInsertFifthNode();

	TestToStrings();
	TestInsertRandomTests();

	TestCopyConstructor();

	TestContains();
	TestGetMinimumMaximum();

	TestRemove();

	cout << "ALL TESTS PASSED!!" << endl;
	return 0;
}
