#include<iostream>
#include<cmath>
using namespace std;
int determinant( double matrix[10][10], int n);

int main()
{
    int row_a,colum_a;
    int row_b,colum_b;
    int op_type;
    double z;
    cout<<"Please enter dimensions of Matrix A:\n";
    cin>> row_a>>colum_a;
     cout<<"Please enter dimensions of Matrix B:\n";
     cin>> row_b>>colum_b;
   double mat_a [ 10][10];
      double mat_b [ 10][10];
     double inv[10][10];
    double adj[10][10];
    double mult[10][10];
    cout<<"Please enter values of Matrix A:\n";

    for(int row=0;row<row_a;row++)

     for(int colum=0;colum< colum_a;colum++)
     {
         cin>>mat_a[row][colum];
     }


     cout<<"Please enter values of Matrix B:\n";

           for(int row=0;row<row_b;row++)
          for(int colum=0;colum<colum_b;colum++)
     {
          cin>>mat_b[row][colum];
     }
     adj[0][0]=mat_b[1][1]*mat_b[2][2]-mat_b[1][2]*mat_b[2][1];

    adj[0][1]=-(mat_b[0][1]*mat_b[2][2]-mat_b[0][2]*mat_b[2][1]);

    adj[0][2]=mat_b[0][1]*mat_b[1][2]-mat_b[0][2]*mat_b[1][1];

    adj[1][0]=-(mat_b[1][0]*mat_b[2][2]-mat_b[1][2]*mat_b[2][0]);

    adj[1][1]=mat_b[0][0]*mat_b[2][2]-mat_b[0][2]*mat_b[2][0];

    adj[1][2]=-(mat_b[0][0]*mat_b[1][2]-mat_b[0][2]*mat_b[1][0]);

    adj[2][0]=mat_b[1][0]*mat_b[2][1]-mat_b[1][1]*mat_b[2][0];

    adj[2][1]=-(mat_b[0][0]*mat_b[2][1]-mat_b[0][1]*mat_b[2][0]);

    adj[2][2]=mat_b[0][0]*mat_b[1][1]-mat_b[0][1]*mat_b[1][0];



     z=(1.0/determinant(mat_b,3));
     //for inverse matrix


     for(int row=0;row<row_a;row++)

     for(int colum=0;colum< colum_a;colum++)
     {
         inv[row][colum]=z*adj[row][colum];
     }



     do{
             cout<<"Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):\n";
     cin>>op_type;
        switch(op_type)
     {
         case 1:
              if(colum_a==colum_b&&row_a==row_b)
              {
                  for(int row=0;row<row_b;row++)
   {
           for(int colum=0;colum<colum_b;colum++)
     {
          cout <<mat_a[row][colum]+mat_b[row][colum]<<" ";
     }
      cout<<"\n";
   }
              }
              else
                cout<<"The operation you chose is invalid for the given matrices.\n";
              break;
         case 2:
              if(colum_a==colum_b&&row_a==row_b)
              {
                   for(int row=0;row<row_b;row++)
   {
           for(int colum=0;colum<colum_b;colum++)
     {
          cout <<mat_a[row][colum]-mat_b[row][colum]<<" ";
     }
      cout<<"\n";
   }
              }
               else
                cout<<"The operation you chose is invalid for the given matrices.\n";

   break;
         case 3:
             if(colum_a==row_b)
             {
                 for(int row=0;row<row_a;row++)
        {
            for(int colum=0;colum<colum_b;colum++)
               {
                  mult[row][colum]=0;
                       for(int k=0;k<row_b;k++)
                         {
                          mult[row][colum]+=mat_a[row][k]*mat_b[k][colum];
                   }
                }
               }


            for(int row=0;row<row_a;row++)
     {
          for(int colum=0;colum<colum_b;colum++)

          cout <<mult[row][colum]<<" ";

          cout<<endl;
     }

   }

             else
                cout<<"The operation you chose is invalid for the given matrices.\n";
             break;
         case 4:
             if(determinant(mat_b,3)!=0)
             {
             for(int row=0;row<3;row++)
        {
            for(int colum=0;colum<3;colum++)
               {
                  mult[row][colum]=0;
                       for(int k=0;k<row_b;k++)
                         {
                          mult[row][colum]+=mat_a[row][k]*inv[k][colum];
                   }
                }
               }


            for(int row=0;row<3;row++)
     {
          for(int colum=0;colum<3;colum++)
          {

            if(round(mult[row][colum])==-0)
          {
              cout<<0<<" ";

          }
          else
          {
             cout <<round(mult[row][colum])<<" ";
          }


          }
          cout<<endl;
     }
             }
              else
            cout<<"The operation you chose is invalid for the given matrices.\n";

        break;

    case 5:
        if (row_a==colum_a)
        {
            cout<< determinant(mat_a,row_a)<<"\n";
        }
        else
            cout<<"The operation you chose is invalid for the given matrices.\n";

        break;

        case 6:
        if (row_b==colum_b)
        {
            cout<<determinant(mat_b,row_b)<<"\n";
        }
        else
            cout<<"The operation you chose is invalid for the given matrices.\n";
        break;

}
     }while(op_type!=7);
     cout<<"Thank you!";
}

   int determinant( double mat[10][10], int row)
   {
   int sum = 0;
   double submatrix[10][10];

   if(row==1||row==2)
    {
        if(row==1)
            return mat[0][0];
        else
            return mat[0][0]*mat[1][1]-mat[1][0]*mat[0][1];
    }
   else
    {
      for (int x = 0; x < row; x++)
       {
         int subrows = 0;
         for (int rows = 1; rows < row; rows++)
         {
            int subcolums = 0;
            for (int colums = 0; colums < row; colums++)
             {
               if (colums == x)
               continue;
               submatrix[subrows][subcolums] = mat[rows][colums];
               subcolums++;
            }
            subrows++;
         }
         sum = sum + (pow(-1, x) * mat[0][x] * determinant( submatrix, row - 1 ));
      }
   }
   return sum;


}


