void TestInsertRandomTests(){
	cout << "Testing Random Insert Stuff..." << endl;
	cout << "\t This test passes if it doesn't crash and valgrind reports no issues" << endl;
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(15);
	rbt->Insert(13);
	rbt->Insert(20);
	rbt->Insert(12);
	cout << endl;
	//cout << "tree: " << rbt->ToInfixString() << endl;
	delete rbt;
	
	
	// probably should have a delete or something here
	rbt = new RedBlackTree();
	//cout << endl << "NEW TREE" << endl;
	rbt->Insert(12);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(11);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(15);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(5);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(13);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	rbt->Insert(7);
	//cout << "tree: "  << rbt->ToInfixString() << endl;
	delete rbt;
	
	
	rbt = new RedBlackTree();
	//cout << endl << "NEW TREE" << endl;
	rbt->Insert(12);
	//cout << "tree: "  << rbt->ToPrefixString() << endl;
	rbt->Insert(10);
	//cout << "tree: "  << rbt->ToPrefixString() << endl;
	rbt->Insert(8);
	//cout << "tree: "  << rbt->ToPrefixString() << endl;
	delete rbt;


	rbt = new RedBlackTree();
	rbt->Insert(11);
	rbt->Insert(9);
	rbt->Insert(4);
	rbt->Insert(31);
	rbt->Insert(23);
	rbt->Insert(52);
	//cout << rbt->ToPrefixString() << endl;
	assert(rbt->ToPrefixString() == " B9  B4  R23  B11  B31  R52 ");
	delete rbt;
	
	
	cout << "PASSED!" << endl << endl;
}


void BigTreeTest(){ 
	cout << "Testing Construction of Big Tree..." << endl;
	RedBlackTree rbt = RedBlackTree();
	rbt.Insert(12);
	rbt.Insert(10);
	rbt.Insert(0);
	rbt.Insert(11);
	rbt.Insert(3);
	rbt.Insert(9);
	rbt.Insert(2);
	rbt.Insert(7);
	rbt.Insert(1);
	rbt.Insert(4);
	rbt.Insert(6);
	rbt.Insert(8);
	rbt.Insert(37);
	rbt.Insert(5);
	rbt.Insert(72);
	rbt.Insert(55);
	rbt.Insert(90);
	rbt.Insert(92);
	rbt.Insert(20);
	rbt.Insert(13);
	rbt.Insert(57);
	rbt.Insert(30);
	rbt.Insert(64);
	rbt.Insert(69);
	rbt.Insert(50);
	rbt.Insert(67);
	rbt.Insert(99);
	rbt.Insert(89);
	rbt.Insert(33);

	assert(rbt.ToPrefixString() == " B12  R7  B3  B1  R0  R2  B5  R4  R6  B10  B9  R8  B11  R55  B20  B13  R37  B30  R33  B50  B69  R64  B57  B67  R90  B72  R89  B92  R99 ");

	cout << "PASSED!" << endl << endl;
}


void TestInsertWithRecursiveFixUp(){
	cout << "Testing Recursive FixUp..." << endl;
	// Red uncle, and we "move the blackness up"
	// the makes the grandparent red and that might cause issues
	// at the grand-parent level.
	// This may repeat until the root node (which must be black)
	RedBlackTree *rbt = new RedBlackTree();
	rbt->Insert(400);
	rbt->Insert(800);
	rbt->Insert(200);
	rbt->Insert(600);
	rbt->Insert(150);
	rbt->Insert(900);
	rbt->Insert(300);
	rbt->Insert(100);
	rbt->Insert(175);
	rbt->Insert(160); // does some weird stuff!
	assert(rbt->ToPrefixString() == " B200  R150  B100  B175  R160  R400  B300  B800  R600  R900 ");
	rbt->Insert(185);
	rbt->Insert(180); // does a recursive fix-up
	assert(rbt->ToPrefixString() == " B200  B150  B100  R175  B160  B185  R180  B400  B300  B800  R600  R900 ");
	//cout << rbt->ToPrefixString() << endl;
	delete rbt;
	
	cout << "PASSED!" << endl << endl;
}
