
#include <iostream>
#include <cassert>
#include <random>
#include "RedBlackTree.h"

using namespace std;

void TestSimpleConstructor()
{
	cout << "Testing Simple Constructor... " << endl;
	RedBlackTree rbt = RedBlackTree();
	cout << "empty r-b-tree: " << rbt.ToInfixString() << endl;
	assert(rbt.ToInfixString() == "");

	cout << "PASSED!" << endl
		 << endl;
}

void TestInsertFirstNode()
{
	cout << "Testing Insert One Node..." << endl;
	RedBlackTree rbt = RedBlackTree();
	rbt.Insert(30);
	// cout << "rbt: " << rbt.ToPrefixString() << endl;
	assert(rbt.ToPrefixString() == " B30 ");

	RedBlackTree rbt1 = RedBlackTree();
	rbt1.Insert(-1);
	// cout << "rbt: " << rbt.ToPrefixString() << endl;
	assert(rbt1.ToPrefixString() == " B-1 ");

	RedBlackTree rbt2 = RedBlackTree();
	// cout << "rbt: " << rbt.ToPrefixString() << endl;
	assert(rbt2.ToPrefixString() == "");

	RedBlackTree rbt4 = RedBlackTree();
	rbt4.Insert(44);
	rbt4.Insert(55);
	rbt4.Insert(66);
	try
	{
		rbt4.Insert(66);
		assert(false);
	}
	catch (const invalid_argument &e)
	{
	}

	cout << "PASSED!" << endl
		 << endl;
}

void TestInsertSecondNode()
{
	cout << "Testing Insert Second Node..." << endl;
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(30); // leak here
	rbt->Insert(15);
	cout << "rbt: " << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B30  R15 ");
	delete rbt;

	rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(45);
	// cout << "rbt: " << rbt->ToPrefixString() << endl;
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
	// cout << "rbt: " << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B15  R10  R30 ");
	delete rbt;

	RedBlackTree *rbtt = new RedBlackTree();
	rbtt->Insert(30);
	rbtt->Insert(40);
	rbtt->Insert(50);
	// cout << "rbt: " << rbtt->ToPrefixString() << endl;
	assert(rbtt->ToPrefixString() == " B40  R30  R50 ");
	delete rbtt;

	rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(15);
	rbt->Insert(25); // Right Left
					 // cout << "rbt: " << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B25  R15  R30 ");
	delete rbt;

	rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(15);
	rbt->Insert(45); // Easy case
	// cout << "rbt: " << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B30  R15  R45 ");
	delete rbt;

	rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(45);
	rbt->Insert(50); // Easy case
	//  cout << "rbt: " << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B45  R30  R50 ");
	delete rbt;

	rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(45);
	rbt->Insert(40); // Easy case
	//  cout << "rbt: " << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B40  R30  R45 ");
	delete rbt;

	cout << "PASSED!" << endl
		 << endl;
}

void TestInsertFourthNode()
{
	cout << "Testing Insert Fourth Node..." << endl;

	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(15);
	rbt->Insert(10);
	rbt->Insert(5);
	// cout << "rbt: " << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B15  B10  R5  B30 ");
	delete rbt;

	rbt = new RedBlackTree();
	rbt->Insert(30);
	rbt->Insert(40);
	rbt->Insert(10);
	rbt->Insert(60);
	// cout << "rbt: " << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B30  B10  B40  R60 ");
	delete rbt;

	rbt = new RedBlackTree();
	rbt->Insert(24);
	rbt->Insert(20);
	rbt->Insert(30);
	rbt->Insert(51);
	// cout << "rbt: " << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B24  B20  B30  R51 ");
	delete rbt;

	rbt = new RedBlackTree();
	rbt->Insert(42);
	rbt->Insert(67);
	rbt->Insert(1);
	rbt->Insert(9);
	// cout << "rbt: " << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B42  B1  R9  B67 ");
	delete rbt;

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
	// cout << "result: " << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B30  B15  R10  R25  B45 ");

	rbt = new RedBlackTree();
	rbt->Insert(11);
	rbt->Insert(23);
	rbt->Insert(9);
	rbt->Insert(52);
	rbt->Insert(31);
	rbt->Insert(4);
	// cout << "result: " <<rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B11  B9  R4  B31  R23  R52 ");

	rbt = new RedBlackTree();
	rbt->Insert(11);
	rbt->Insert(23);
	rbt->Insert(4);
	rbt->Insert(6);
	rbt->Insert(77);
	// cout << "result: " <<rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B11  B4  R6  B23  R77 ");
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

	RedBlackTree rbt1 = RedBlackTree();
	assert(rbt1.ToPrefixString() == "");
	assert(rbt1.ToInfixString() == "");
	assert(rbt1.ToPostfixString() == "");

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

	RedBlackTree rbt3 = RedBlackTree();
	rbt3.Insert(11);
	assert(rbt3.ToPrefixString() == " B11 ");
	RedBlackTree rbt4 = RedBlackTree(rbt3);
	assert(rbt3.ToPrefixString() == rbt4.ToPrefixString());
	rbt3.Insert(20);
	assert(rbt3.ToPrefixString() != rbt4.ToPrefixString());
	cout << "PASSED!" << endl
		 << endl;

	RedBlackTree rbt6 = RedBlackTree();
	assert(rbt6.ToPrefixString() == "");
	RedBlackTree rbt5 = RedBlackTree(rbt6);
	assert(rbt6.ToPrefixString() == rbt5.ToPrefixString());
	rbt6.Insert(20);
	assert(rbt6.ToPrefixString() != rbt5.ToPrefixString());

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

	assert(rbt->Contains(40));
	assert(rbt->Contains(22));
	assert(rbt->Contains(15));
	assert(rbt->Contains(31));
	assert(rbt->Contains(55));
	assert(rbt->Contains(12));
	assert(rbt->Contains(17));
	assert(rbt->Contains(29));
	assert(rbt->Contains(34));
	assert(!rbt->Contains(21));
	assert(!rbt->Contains(32));
	assert(!rbt->Contains(54));
	assert(!rbt->Contains(66));

	delete rbt;

	RedBlackTree *rbt1 = new RedBlackTree();
	assert(!rbt1->Contains(66));
	delete rbt1;

	cout << "PASSED!" << endl
		 << endl;
}

void TestGetMinimumMaximum()
{
	cout << "Testing Get Minimum and Get Maximum..." << endl;

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

	assert(rbt->GetMin() == 12);
	assert(rbt->GetMax() == 55);
	delete rbt;

	RedBlackTree *rbt1 = new RedBlackTree();
	rbt1->Insert(40);

	assert(rbt1->GetMin() == 40);
	assert(rbt1->GetMax() == 40);
	delete rbt1;

	RedBlackTree *rbt2 = new RedBlackTree();
	rbt2->Insert(40);
	rbt2->Insert(12);
	rbt2->Insert(50);

	assert(rbt2->GetMin() == 12);
	assert(rbt2->GetMax() == 50);
	delete rbt2;

	RedBlackTree *rbt3 = new RedBlackTree();

	assert(rbt3->GetMin() == 0);
	assert(rbt3->GetMax() == 0);
	delete rbt3;

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

	cout << "ALL TESTS PASSED!!" << endl;
	return 0;
}
