int size = 11;
 std::string** grid = new std::string*[size];

 for (int i = 0; i < size; i++)
 {
   grid[i] = new std::string[size];
 }

 for (int i = 0; i < size; i++)
 {
   for (int j = 0; j < size; j++)
   {
     if (i == 0)
     {
//	Convert to ASCII For Loop
      grid[i][0] = '|';
      grid[i][1] = " A";
      grid[i][2] = "B";
      grid[i][3] = "C";
      grid[i][4] = "D";
      grid[i][5] = "E";
      grid[i][6] = "F";
      grid[i][7] = "G";
      grid[i][8] = "H";
      grid[i][9] = "I";
      grid[i][10] = "J";
     }
     else if (j == 0)
     {
      grid[1][j] = "1 ";
      grid[2][j] = "2 ";
      grid[3][j] = "3 ";
      grid[4][j] = "4 ";
      grid[5][j] = "5 ";
      grid[6][j] = "6 ";
      grid[7][j] = "7 ";
      grid[8][j] = "8 ";
      grid[9][j] = "9 ";
      grid[10][j] = "10";
     }
     else
     {
      grid[i][j] = '.';
     }
   std::cout << grid[i][j] << " ";
   }
  std::cout << std::endl;
   //ADD in later
// 	 for (int i = 0; i < size; i++)
//  {
// 	delete[] grid[i];
//  }
// 	delete[] grid;
 }

 std::cout << std::endl;
 std::cout << std::endl;

//2ND GRID

 int size2 = 11;
 std::string** gridb = new std::string*[size2];

 for (int i = 0; i < size2; i++)
 {
   gridb[i] = new std::string[size2];
 }

 for (int i = 0; i < size2; i++)
 {
   for (int j = 0; j < size2; j++)
   {
     if (i == 0)
     {
 //Convert to ASCII For loop
    gridb[i][0] = '|';
    gridb[i][1] = " A";
    gridb[i][2] = "B";
    gridb[i][3] = "C";
    gridb[i][4] = "D";
    gridb[i][5] = "E";
    gridb[i][6] = "F";
    gridb[i][7] = "G";
    gridb[i][8] = "H";
    gridb[i][9] = "I";
    gridb[i][10] = "J";
     }
     else if (j == 0)
     {
      gridb[1][j] = "1 ";
      gridb[2][j] = "2 ";
      gridb[3][j] = "3 ";
      gridb[4][j] = "4 ";
      gridb[5][j] = "5 ";
      gridb[6][j] = "6 ";
      gridb[7][j] = "7 ";
      gridb[8][j] = "8 ";
      gridb[9][j] = "9 ";
      gridb[10][j] = "10";
    }
    else
    {
     gridb[i][j] = '.';
    }
    std::cout << gridb[i][j] << " ";
   }
   std::cout << std::endl;
 }
 //ADD in later
// 	 for (int i = 0; i < size; i++)
//  {
// 	delete[] grid[i];
//  }
// 	delete[] grid;
}
