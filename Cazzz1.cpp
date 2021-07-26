#include<iostream>

using namespace std;

  class MatRev
   {
   	  private:
   	  	  int arr[100][100], row, col;
   	  	  
   	  public:
		 
		  MatRev(int m, int n)	
		   {
		   	  row = m;
		   	  col = n;
		   	 
		   }
		   
		   
		   void fillArray()
		      {
		      	  cout<<"Enter Array elements = ";
					int i, j;
		      	  
		      	  for(i=0;i<row;i++)
		      	   {
		      	   	 for(j=0;j<col;j++)
		      	   	   { 
		      	   	      cin>>arr[i][j];
						}
						//cout<"\n";
					 }
			  }
			  
			void display()
			    {
			    	int i, j;
		      	  
		      	  for(i=0;i<row;i++)
		      	   {
		      	   	 for(j=0;j<col;j++)
		      	   	   { 
		      	   	      cout<<arr[i][j];
		      	   	      cout<<" ";
						}
						cout<<"\n";
					 }
				}
				
			int reverse(int num)
			      {
			      	  int i, r = 0, rev = 0;
						
						for(i=1;i<=num;i++) 
						  {
						 	 r = num % 10;
						 	 rev = (rev*10)+r;
						 	 num = num/10;
						  }
						  
						  return rev;
			      }
			      
			 void reverseMatrix(MatRev ref)
			    {
			    	int i, j;
			    	
			    	for(i=0;i<row;i++)
		      	      {
		      	   	      for(j=0;j<col;j++)
		      	   	        { 
		      	   	           this->arr[i][j] = reverse(ref.arr[i][j]);
					    	 }
					        	//cout<<"\n";
					  }
			    	
				}
				
				void show()
				   {
				   	   	int i, j;
		      	  
		      	        for(i=0;i<row;i++)
		      	           {
		      	   	          for(j=0;j<col;j++)
		      	   	           { 
		      	   	             cout<<arr[i][j];
					        	}
						          cout<<"\n";
					        }
				   	   
				   }
   	
   };
   
   
      int main()
        {
        	  MatRev A(3,3), B(3,3);
        	  
        	  A.fillArray();
        	  A.display();
        	  B.reverseMatrix(A);
        	  A.show();
        	  
		}
