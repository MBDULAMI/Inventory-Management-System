#include <iostream>
#include <string>
#include<iomanip>
using namespace std;

//structure for the goods details
  struct GoodDetail 
{
	int goodCode;   
	string goodName;  
	float goodPrice;  
	string goodType;
};

//structure for the supplier details 
  struct SupplierDetail 
{
	int supplierId;
    string supplierName;
    int supplierPhone;
    string supplierCompany;
};

 
//structure for assign
struct SuperMarket{
	GoodDetail assignGood;
	SupplierDetail assignSupplier;
};

//declaring linkList structure for the goods
  struct GoodsNode 
{
	GoodDetail Goodinfo;
	GoodsNode * next;

} *goodshead = NULL , *goodcur=NULL , *goodtail=NULL ;

 
//declaring linkList structure for the supplier
  struct SuppliersNode 
{
	SupplierDetail Supplierinfo; 
	SuppliersNode * next;

} *supplierhead = NULL , *suppliercur = NULL, *suppliertail=NULL;

 
///declaring circular linkedList structure for assigning goods to suppliers 
  struct AssigningNode 
{
	SuperMarket assigned; 
	AssigningNode *next;

} *assigncur=NULL, *assigntail=NULL;


//function to check whether the good list is empty or not
  bool isGoodListEmpty() 
{
  return (goodshead == NULL);
}

//function to check whether the supplier list is empty or not
  bool isSupplierListEmpty() 
{
	return (supplierhead == NULL);
}

//function to check if there any ggod assigned to a supplier 
 bool isAssignListEmpty()
 {
 	return (assigntail==NULL);
 }

//function to check if the goods exist -> using for Update and Delete 
  GoodsNode* GoodsExists(int goodCode)
{
	goodcur=goodshead;
	GoodsNode *temp=NULL;
	
			while(goodcur!=NULL)
				{
					if(goodcur->Goodinfo.goodCode==goodCode)
						{
							temp=goodcur;
							}
						goodcur=goodcur->next;
}
		return temp;
}

///function to keep track of updated and deleted good -> Assign
  AssigningNode* AssigningExists(int key)
{
	assigncur=assigntail;
	AssigningNode *temp=NULL;
	
		if (isAssignListEmpty())
			return temp;
		else 
			{
				do{
		
					if(assigncur->assigned.assignGood.goodCode==key || assigncur->assigned.assignSupplier.supplierId==key)
						{
							temp=assigncur;
						}
						assigncur=assigncur->next;
				}while(assigncur!=assigntail);
			}
		return temp;
}



///function to check if supplier exist -> using for Update and Delete 
  SuppliersNode* SupplierExists(int supplierId)
{
	suppliercur=supplierhead;
	SuppliersNode *temp=NULL;
	
			while(suppliercur!=NULL)
				{
					if(suppliercur->Supplierinfo.supplierId==supplierId)
						{
							temp=suppliercur;
							}
						suppliercur=suppliercur->next;
}
		return temp;
}

 ///1. function to add new goods
  void insertGoods() 
{
  
	GoodsNode * newGoodNode = new GoodsNode; 
	cout << "\n\n\t\t\t\t\t\t\t************** Adding new Good **************" << endl;
	cout << "\n\t\t\t\t\t\t\t Please Enter the Product Code: ";
	cin >> newGoodNode->Goodinfo.goodCode;
	cin.ignore (); 
	cout << "\n\t\t\t\t\t\t\t Please Enter the Product Name: ";
	getline (cin, newGoodNode->Goodinfo.goodName);
	cout << "\n\t\t\t\t\t\t\t Please Enter the Product Type: ";
	cin >> newGoodNode->Goodinfo.goodType;
	cin.ignore ();
	cout << "\n\t\t\t\t\t\t\t Please Enter the Product Price: ";
	cin >> newGoodNode->Goodinfo.goodPrice;
  
 
	if(isGoodListEmpty())
    {	
		goodshead = newGoodNode;
		goodtail=newGoodNode;   
}
  
  else
    {
        goodtail->next=newGoodNode;
		newGoodNode = newGoodNode; 
}

}


///2. function to add new supplier
  void insertSupplier() 
{
  
	SuppliersNode * newSupplierNode = new SuppliersNode;
	cout << "\n\n\t\t\t\t\t\t\t************** Adding new Supplier **************" << endl;
	cout << "\n\t\t\t\t\t\t\t Please Enter Commercial Registration Number: "; //unique ID
	cin >> newSupplierNode->Supplierinfo.supplierId;
	cin.ignore ();
	cout << "\n\t\t\t\t\t\t\t Please Enter Primary Contact Name : ";
	getline (cin, newSupplierNode->Supplierinfo.supplierName);
	cout << "\n\t\t\t\t\t\t\t Please Enter Supplier Company Name: ";
    getline(cin,newSupplierNode->Supplierinfo.supplierCompany);
	cout << "\n\t\t\t\t\t\t\t  Enter Contact Phone Number: ";
	cin >> newSupplierNode->Supplierinfo.supplierPhone;
  
    if (isSupplierListEmpty())
    {  
    	supplierhead = newSupplierNode;
    	suppliertail =newSupplierNode; 
}
  
  else
    {
      suppliertail->next=newSupplierNode;
      suppliertail=newSupplierNode;
}
}

//3. function to serach for Goods details
void GoodsSearch()
{
	goodcur=goodshead;
	bool found=false;
	if(isGoodListEmpty())
		cout<<"\n\t\t\t\t\t\t\t The list is empty\n";
	else
		{	
			cout<<"\n\t\t\t\t\t\t\tEnter the Good code to be searched: ";
			int good;
			cin>>good;
			while(goodcur!=NULL)
				{
					if(goodcur->Goodinfo.goodCode==good)
						{
							found=true;
							cout<<"\n\t\t\t\t\t\t\tThe given Good is Avaliable in the List!\n";
							cout<<"\n\n\t\t\t\t\t\t\t-------------- Good Details ---------------";
							cout<<"\n\t\t\t\t\t\t\t Good Code:  " << goodcur->Goodinfo.goodCode << endl;
	  						cout <<"\n\t\t\t\t\t\t\t Good Name:  " << goodcur->Goodinfo.goodName << endl;
							cout<<"\n\t\t\t\t\t\t\t Good Type:  "  << goodcur->Goodinfo.goodType << endl;
	  						cout<<"\n\t\t\t\t\t\t\t Good Price:  "  << goodcur->Goodinfo.goodPrice << endl;

							}
						goodcur=goodcur->next;
}
		if(!found)
			cout<<"\n\t\t\t\t\t\t\t The Good wasn't found in the list.. \n";
}
}


//4. function to serach for suppliers details
  void SuppliersSearch()
{
	suppliercur=supplierhead;
	bool found=false;

	if(isSupplierListEmpty())
		cout<<"\n\t\t\t\t\t\t\tThe list is empty..\n";
	else
		{
			cout<<"\n\t\t\t\t\t\t\tEnter the supplier ID to be searched: ";
			int supplier;
			cin>>supplier;
			while(suppliercur!=NULL)
			{
				if(suppliercur->Supplierinfo.supplierId==supplier)
					{
						found=true;
						cout<<"\n\t\t\t\t\t\t\tThe given Supplier is Avaliable in the List!\n";
				     	cout<<"\n\n\t\t\t\t\t\t\t-------------- Supplier Details ---------------";
						cout<<"\n\t\t\t\t\t\t\t Commercial Registration Number: " << suppliercur->Supplierinfo.supplierId << endl;
	  					cout<<"\n\t\t\t\t\t\t\t Primary Contact Name: "  << suppliercur->Supplierinfo.supplierName << endl;
						cout<<"\n\t\t\t\t\t\t\t Supplier Company Name: "  << suppliercur->Supplierinfo.supplierCompany << endl;
	  					cout<<"\n\t\t\t\t\t\t\t Contact Phone Number: " << suppliercur->Supplierinfo.supplierPhone << endl;
	  
						}
			suppliercur=suppliercur->next;
}
		if(!found)
			cout<<"\n\t\t\t\t\t\t\t The supplier wasn't found in the list.. \n";

}
}

 
//5. function to assign goods to supplier
  void Assign()
   {
  
		int good, supplier;
		AssigningNode * newNode = new AssigningNode; 
		cout<<"\n\t\t\t\t\t\t\t Enter the Product Code: ";
		cin>>good;
		cout<<"\n\t\t\t\t\t\t\t Enter the Commercial Registration Number: ";
		cin>>supplier;
    	GoodsNode *goodptr = GoodsExists(good);
    	SuppliersNode *supplierptr = SupplierExists(supplier);
    	
			if (goodptr == NULL)
  		  		cout<<"\n\t\t\t\t\t\t\t The Product is not Avaliable in the Supermaret.. "<<endl;
			if 	(supplierptr == NULL)
				cout<<"\n\t\t\t\t\t\t\t The Supplier is not Exist.. "<<endl;
				
			else if (goodptr != NULL && supplierptr != NULL)
			 {
			
			 	newNode->assigned.assignGood.goodCode =goodptr->Goodinfo.goodCode;
			 	newNode->assigned.assignGood.goodName =goodptr->Goodinfo.goodName;
			 	newNode->assigned.assignGood.goodType =goodptr->Goodinfo.goodType;
			 	newNode->assigned.assignGood.goodPrice =goodptr->Goodinfo.goodPrice;
			 	
			 	newNode->assigned.assignSupplier.supplierId =supplierptr->Supplierinfo.supplierId;
			 	newNode->assigned.assignSupplier.supplierName =supplierptr->Supplierinfo.supplierName;
			 	newNode->assigned.assignSupplier.supplierCompany =supplierptr->Supplierinfo.supplierCompany;
			 	newNode->assigned.assignSupplier.supplierPhone =supplierptr->Supplierinfo.supplierPhone;
			 	
    			if(isAssignListEmpty())
   					 {	
						assigntail = newNode;
						assigntail->next=newNode;   
					}
  
 				else
   					 {
				        assigntail->next = newNode;
						newNode->next=assigntail;  
						assigntail=newNode;
						
					}
     			cout << "\n\t\t\t\t\t\t\t Goods Assigned Successfully to the Supplier!" << endl;
         } 
		
  }
  
  


// 6. function to update Good node
  void updateGoodNode()
   {
		int good;
		string updatedName, updatedType;
   		int updatedCode;
		float updatedPrice;
   		
		cout<<"\n\t\t\t\t\t\t\t Enter the Product Code: ";
		cin>>good;
		
    	GoodsNode *ptr = GoodsExists(good);
    	AssigningNode *aptr = AssigningExists(good);
  		  if (ptr != NULL)
		 {
    		cout << "\n\t\t\t\t\t\t\t Enter the New Product Code: ";
  			cin >> updatedCode;
  			cin.ignore ();
  			cout << "\n\t\t\t\t\t\t\t Enter the New Product Name: ";
  			getline (cin, updatedName);
  			cout << "\n\t\t\t\t\t\t\t Enter the New Product Type: ";
  			cin >> updatedType;
  			cin.ignore ();
  			cout << "\n\t\t\t\t\t\t\t Enter the New Product Price: ";
  			cin >> updatedPrice;
    	
    		ptr->Goodinfo.goodCode = updatedCode;
    	 	ptr->Goodinfo.goodName=updatedName ;
    	 	ptr->Goodinfo.goodType =updatedType;
    	    ptr->Goodinfo.goodPrice=updatedPrice;
    	    if (aptr!=NULL)
    	    {
    	   	 	aptr->assigned.assignGood.goodCode = updatedCode;
	    	    aptr->assigned.assignGood.goodName = updatedName;
	    	    aptr->assigned.assignGood.goodType = updatedType;
	    	    aptr->assigned.assignGood.goodPrice = updatedPrice;	
			}
    	    
     		cout << "\n\t\t\t\t\t\t\t Product Data Updated Successfully!" << endl;
         } 
		else 
		{
   		   cout << "\n\t\t\t\t\t\t\t Product Doesn't exist with Code Number: " << good << endl;
   		 }

  }
  


  //7. function to update supplier node
  void updateSupplierNode()
   {
		int supplier;
		string updatedName, updatedCompanyName;
   		int updatedID, updatedPhone;
   		
		cout<<"\n\t\t\t\t\t\t\t Enter the Supplier Commercial Registration Number: ";
		cin>>supplier;
			
    	SuppliersNode *ptr = SupplierExists(supplier);
    	AssigningNode *aptr = AssigningExists(supplier);
  		  if (ptr != NULL)
		 {
    		cout << "\n\t\t\t\t\t\t\t Enter the New Commercial Registration Number:: ";
  			cin >> updatedID;
  			cin.ignore ();
  			cout << "\n\t\t\t\t\t\t\t Enter the New Primary Contact Name: ";
  			getline (cin, updatedName);
  			cout << "\n\t\t\t\t\t\t\t Enter the New Supplier Company Name: ";
  			cin >> updatedCompanyName;
  			cin.ignore ();
  			cout << "\n\t\t\t\t\t\t\t  Enter the New Primary Contact Phone Number: ";
  			cin >> updatedPhone;
    	
    		ptr->Supplierinfo.supplierId = updatedID;
    	 	ptr->Supplierinfo.supplierName=updatedName ;
    	 	ptr->Supplierinfo.supplierCompany =updatedCompanyName;
    	    ptr->Supplierinfo.supplierPhone=updatedPhone;
    	    if (aptr!=NULL)
    	    {
    	   	 	aptr->assigned.assignSupplier.supplierId =updatedID;
			 	aptr->assigned.assignSupplier.supplierName =updatedName;
			 	aptr->assigned.assignSupplier.supplierCompany =updatedCompanyName;
			 	aptr->assigned.assignSupplier.supplierPhone =updatedPhone;
			}
     		cout << "\n\t\t\t\t\t\t\t Supplier Data Updated Successfully!" << endl;
         } 
		else 
		{
   		   cout << "\n\t\t\t\t\t\t\t Supplier Doesn't exist with Commercial Registration Number: " << supplier << endl;
   		 }

  }


void assignDisplay()
	{
		
		if (isAssignListEmpty())
		cout << "\n\t\t\t\t\t\t\t There is no Good assigned to Supplier \n";
  		
  	
  
  else
    
    {
		AssigningNode * temp = assigntail;
		     
		cout << "\n\n\t\t\t\t\t\t\t************** Assigning List **************" << endl;
		do
		{
				cout<<"\n\n\t\t\t\t\t\t\t" <<'|'<< setw(10)<< "\t Product "<< setw(8)<<'|'<< setw(10) << "   Assigned to "<< setw(7) << '|' << endl;
				cout <<"\n\n\t\t\t\t\t\t\t"<<'|'<< setw(12)<<temp->assigned.assignGood.goodName << setw(12)<<'|'<< setw(12) 
				 << temp->assigned.assignSupplier.supplierCompany<< setw(10) << '|' << endl;
				cout << "\n\t\t\t\t\t\t\t -----------------------------------------" << endl;
				temp = temp->next;
	
			}while (temp != assigntail);
			cout << "\n\n\t\t\t\t\t\t\t*******************************************" << endl;
		}
	}


///8. function to display goods list
 void displayGoodsList() 
{
   if (isGoodListEmpty ())
		cout << "\n\t\t\t\t\t\t\t There is no Goods in the list..\n";
  
  else
    
    {
		GoodsNode * temp = goodshead;
		     
		cout << "\n\n\t\t\t\t\t\t\t************** Goods List **************" << endl;
		     
		while (temp != NULL)
			{
				cout<<"\n\t\t\t\t\t\t\t\t   Good Code:  " << temp->Goodinfo.goodCode << endl;		  
				cout <<"\n\t\t\t\t\t\t\t\t  Good Name:  " << temp->Goodinfo.goodName << endl;		  
				cout<<"\n\t\t\t\t\t\t\t\t   Good Type:  "  << temp->Goodinfo.goodType << endl;	  
				cout<<"\n\t\t\t\t\t\t\t\t   Good Price:  "  << temp->Goodinfo.goodPrice << endl;		
				cout << "\n\t\t\t\t\t\t\t  --------------------------------------" << endl;
			
				
				temp = temp->next;
	
			}
			assignDisplay();
		}
}


///9. function to display suppliers list
  void displaySuppliersList() 
{
	if (isSupplierListEmpty())
    	cout << "\n\t\t\t\t\t\t\t There is no supplier in the list..\n";
  
  else
    {
		SuppliersNode * temp = supplierhead;
		      
		cout << "\n\n\t\t\t\t\t\t\t************** Suppliers List **************" << endl;
		      
		while (temp != NULL)
	{
		cout<<"\n\t\t\t\t\t\t\t\t Commercial Registration Number: " << temp->Supplierinfo.supplierId << endl;		  
		cout<<"\n\t\t\t\t\t\t\t\t Primary Contact Name: "  << temp->Supplierinfo.supplierName << endl;	  
		cout<<"\n\t\t\t\t\t\t\t\t Supplier Company Name: "  << temp->Supplierinfo.supplierCompany << endl;	  
		cout<<"\n\t\t\t\t\t\t\t\t Primary Contact Phone Number: " << temp->Supplierinfo.supplierPhone << endl;
		cout << "\n\t\t\t\t\t\t\t  --------------------------------------" << endl;
		temp = temp->next;
	
		}
		assignDisplay();
}

 
}


//delete Assign node
void deleteAssign(int key)
   {
   	 AssigningNode * ptr = new AssigningNode;
	 ptr = AssigningExists(key);

     if (ptr==NULL) 
    	return;
     else 
	 {

      if (ptr==assigntail) //the last node
	   {
        if (assigntail->next == ptr) {
         	 assigntail = NULL;
				
        } 
		else
		 {
	          AssigningNode * curr;
	          curr = assigntail-> next;
	          while (curr->next != assigntail) 
			  {
	            curr = curr-> next;
	          }
		          curr-> next = assigntail -> next;
		          assigntail =curr;
	    }
      }
	  
	  else 
	  {
        AssigningNode * temp = NULL;
        AssigningNode * prevptr = assigntail;
        AssigningNode * currentptr = assigntail -> next;
        while (currentptr != NULL)
		 {
          if (currentptr->assigned.assignGood.goodCode ==key || currentptr->assigned.assignSupplier.supplierId ==key ) 
		  {
            temp = currentptr;
            currentptr = NULL;
          } 
		  else 
		  {
            prevptr = prevptr -> next;
            currentptr = currentptr -> next;
          }
        }

        prevptr -> next = temp -> next;

      }

    }
   
    	delete ptr;

  }


 //10. Delete good node 
 void deleteGoodNode()
 {
 		int good;
		cout<<"\n\t\t\t\t\t\t\t Enter the Product Code you want to be deleted: ";
		cin>>good;
		GoodsNode *ptr = new GoodsNode;
		deleteAssign(good);
		if (goodshead == NULL) //when the list is empty
		{
			cout << "\n\t\t\t\t\t\t\t The Good List already Empty. Cannot delete.." << endl;
		}
		else if (goodshead != NULL) 
		{
			if (goodshead->Goodinfo.goodCode == good) //Deleted the First Node
			{
				ptr->Goodinfo.goodCode=goodshead->Goodinfo.goodCode;
				ptr->Goodinfo.goodName=goodshead->Goodinfo.goodName;
				ptr->Goodinfo.goodPrice=goodshead->Goodinfo.goodPrice;
				ptr->Goodinfo.goodType=goodshead->Goodinfo.goodType;
				cout<<"\n\t\t\t\t\t\t\t The given Good has been deleted Successfully!\n";
				cout<<"\n\n\t\t\t\t\t\t\t-------------- Good Details ---------------";
				cout<<"\n\t\t\t\t\t\t\t Product Code: "<<ptr->Goodinfo.goodCode<<endl;
				cout<<"\n\t\t\t\t\t\t\t Product Name: "<<ptr->Goodinfo.goodName<<endl;
				cout<<"\n\t\t\t\t\t\t\t Product Type: "<<ptr->Goodinfo.goodType<<endl;
				cout<<"\n\t\t\t\t\t\t\t Product Price: "<<ptr->Goodinfo.goodPrice<<endl;
				goodshead = goodshead -> next;
				delete ptr;
			} 
			else 
		{
			GoodsNode * temp = NULL;
			GoodsNode * prevptr = goodshead;
			GoodsNode * currentptr = goodshead->next;
			while (currentptr != NULL) 
		{ 
			if (currentptr->Goodinfo.goodCode == good)
			 {
				temp = currentptr;
				currentptr = NULL;
		} 
		else 
		{
			prevptr = prevptr -> next;
			currentptr = currentptr -> next;
		}
		}
		if (temp != NULL) 
		{
			    ptr->Goodinfo.goodCode=currentptr->Goodinfo.goodCode;
				ptr->Goodinfo.goodName=currentptr->Goodinfo.goodName;
				ptr->Goodinfo.goodPrice=currentptr->Goodinfo.goodPrice;
				ptr->Goodinfo.goodType=currentptr->Goodinfo.goodType;
				cout<<"\n\t\t\t\t\t\t\t The given Good has been deleted Successfully!\n";
				cout<<"\n\n\t\t\t\t\t\t\t-------------- Good Details ---------------";
				cout<<"\n\t\t\t\t\t\t\t Product Code: "<<ptr->Goodinfo.goodCode<<endl;
				cout<<"\n\t\t\t\t\t\t\t Product Name: "<<ptr->Goodinfo.goodName<<endl;
				cout<<"\n\t\t\t\t\t\t\t Product Type: "<<ptr->Goodinfo.goodType<<endl;
				cout<<"\n\t\t\t\t\t\t\t Product Price: "<<ptr->Goodinfo.goodPrice<<endl;
				prevptr -> next = temp -> next;
				delete ptr;
	}
	 else 
	 {
		cout << "\n\t\t\t\t\t\t\t Product Doesn't exist with Code Number: " << good << endl;
	}
}
}

}

//10. Delete supplier node
 void deleteSupplierNode()
 {
 		int supp;
		cout<<"\n\t\t\t\t\t\t\t Enter the Commercial Registration Number of the Supplier; to Delete it: ";
		cin>>supp;
		SuppliersNode *ptr = new SuppliersNode;
		deleteAssign(supp);
		if (supplierhead == NULL) //when the list is empty
		{
			cout << "\n\t\t\t\t\t\t\t The Supplier List already Empty. Cannot delete.." << endl;
		}
		else if (supplierhead != NULL) 
		{
			if (supplierhead->Supplierinfo.supplierId == supp) //Deleted the First Node
			{
				ptr->Supplierinfo.supplierId=supplierhead->Supplierinfo.supplierId;
				ptr->Supplierinfo.supplierName=supplierhead->Supplierinfo.supplierName;
				ptr->Supplierinfo.supplierPhone=supplierhead->Supplierinfo.supplierPhone;
				ptr->Supplierinfo.supplierCompany=supplierhead->Supplierinfo.supplierCompany;
				cout<<"\n\t\t\t\t\t\t\t The Supplier has been deleted Successfully!\n";
				cout<<"\n\n\t\t\t\t\t\t\t-------------- Supplier Details ---------------";			
				cout<<"\n\t\t\t\t\t\t\t Commercial Registration Number: "<<ptr->Supplierinfo.supplierId<<endl;
				cout<<"\n\t\t\t\t\t\t\t Primary Contact Name: "<<ptr->Supplierinfo.supplierName<<endl;
				cout<<"\n\t\t\t\t\t\t\t Primary Contact Phone Number: "<<ptr->Supplierinfo.supplierPhone<<endl;
				cout<<"\n\t\t\t\t\t\t\t Supplier Company Name: "<<ptr->Supplierinfo.supplierCompany<<endl;
				supplierhead = supplierhead -> next;
				delete ptr;
			} 
			else 
		{
			SuppliersNode * temp = NULL;
			SuppliersNode * prevptr = supplierhead;
			SuppliersNode * currentptr = supplierhead->next;
			while (currentptr != NULL) 
		{ 
			if (currentptr->Supplierinfo.supplierId == supp)
			 {
				temp = currentptr;
				currentptr = NULL;
		} 
		else 
		{
			prevptr = prevptr -> next;
			currentptr = currentptr -> next;
		}
		}
		if (temp != NULL) 
		{
			    ptr->Supplierinfo.supplierId=currentptr->Supplierinfo.supplierId;
				ptr->Supplierinfo.supplierName=currentptr->Supplierinfo.supplierName;
				ptr->Supplierinfo.supplierPhone=currentptr->Supplierinfo.supplierPhone;
				ptr->Supplierinfo.supplierCompany=currentptr->Supplierinfo.supplierCompany;
				cout<<"\n\t\t\t\t\t\t\t The Supplier has been deleted Successfully!\n";
				cout<<"\n\n\t\t\t\t\t\t\t-------------- Supplier Details ---------------";			
				cout<<"\n\t\t\t\t\t\t\t Commercial Registration Number: "<<ptr->Supplierinfo.supplierId<<endl;
				cout<<"\n\t\t\t\t\t\t\t Primary Contact Name: "<<ptr->Supplierinfo.supplierName<<endl;
				cout<<"\n\t\t\t\t\t\t\t Primary Contact Phone Number: "<<ptr->Supplierinfo.supplierPhone<<endl;
				cout<<"\n\t\t\t\t\t\t\t Supplier Company Name: "<<ptr->Supplierinfo.supplierCompany<<endl;
				prevptr -> next = temp -> next;
				delete ptr;
	}
	 else 
	 {
		cout << "\n\t\t\t\t\t\t\t Supplier Doesn't exist with Commercial Registration Number: " << supp << endl;
}
}
}

}

int main()
{
	int option1, option2, key, updatedValue;
	do
    { 
      
cout << "\n";
      
cout << "\n";
      
cout << "\n";
      
cout <<
	"                                                       *************************************************"
	<< endl;
      
cout <<
	"                                                       ***************** Main|||Menue ******************"
	<< endl;
      
cout <<
	"                                                       *************************************************"
	<< endl;
      
cout <<
	"                                                            *     Press 1 for Goods Menue        *"
	<< endl;
      
cout <<
	"                                                            *     Press 2 for  Supplier Menue    *"
	<< endl;
cout <<
	"                                                            *     Press 3 To Display Assign list *"
	<< endl;
cout <<
	"                                                            *     Press 0 To Exist               *"
	<< endl;
	
      
cout <<
	"                                                       *************************************************"
	<< endl;
      
cout <<
	"                                                        Enter an Option : ";
      
cin >> option1;
	
	switch(option1)	
	{
		case 0:
			break;
			
		case 1:
			do{
  
cout << "\n";
      
cout << "\n";
      
cout << "\n";
      
cout << "\n";
      
cout <<
	"                                                       *************************************************"	<< endl;
      
cout <<
	"                                                       ***************** Goods|||Menue *****************"
	<< endl;
      
cout <<
	"                                                       *************************************************"
	<< endl;
      
cout <<
	"                                                       *       Press 1 To Add new Goods                *"
	<< endl; 
    cout <<
	"                                                       *       Press 2 To Assign Goods to Supplier     *"
	<< endl;  
cout <<
	"                                                       *       Press 3 To Search Goods Details         *"
	<< endl;
  
cout <<
	"                                                       *       Press 4 To Display Goods List           *"
	<< endl;
cout<<
    "                                                       *       Press 5 To Update Goods Information     *\n";
      
cout <<
	"                                                       *       Press 6 To Delete Good Record           *"
	<< endl;
      
cout <<
	"                                                       *       Press 7 To Clear the Screen             *"
	<< endl;
      
cout <<
	"                                                       *       Press 0 To Return to the Main Menue     *"
	<< endl;
      
cout <<
	"                                                       *************************************************"
	<< endl;
      
cout <<
	"                                                        Enter an Option : ";
      
cin >> option2;
      
switch (option2)
	{
			case 0:
				break;
		
			case 1: 
				insertGoods();
				break;
				 
			case 2:
				Assign();
				break;
			
			case 3:
				GoodsSearch();
				break;
			
			case 4:
				displayGoodsList ();		  
				break;
			
			case 5:
				updateGoodNode();
				break;
			
			case 6:
				deleteGoodNode();
				break; 	
			 
			case 7:
				system ("cls");
				break;
				
			default:
				cout << "\n\t\t\t\t\t\t\t  Enter Proper Option number " << endl;
	  
}


}while(option2!=0);
			break;
			
		case 2:
			do{

cout << "\n";
      
cout << "\n";
      
cout << "\n";
      
cout << "\n";
      
cout <<
	"                                                       *************************************************"	<< endl;
      
cout <<
	"                                                       ***************** Supplier|||Menue **************"
	<< endl;
      
cout <<
	"                                                       *************************************************"
	<< endl;
      
cout <<
	"                                                       *       Press 1 To Add new Supplier             *"
	<< endl; 
      
cout <<
	"                                                       *       Press 2 To Assign Goods to Supplier     *"
	<< endl;
      
cout <<
	"                                                       *       Press 3 To Search Supplier Details      *"
	<< endl;
  
cout <<
	"                                                       *       Press 4 To Display Suppliers List       *"
	<< endl;
cout<<
    "                                                       *       Press 5 To Update Supplier Information  *"
   <<endl;
      
cout <<
	"                                                       *       Press 6 To Delete Supplier Record       *"
	<< endl;
      
cout <<
	"                                                       *       Press 7 To Clear the Screen             *"
	<< endl;
      
cout <<
	"                                                       *       Press 0 To Return to the Main Menue     *"
	<< endl;
      
cout <<
	"                                                       *************************************************"
	<< endl;
      
cout <<
	"                                                        Enter an Option : ";
      
cin >> option2;
      
switch (option2)
	{
		case 0:
		break;
	
		case 1:  
			insertSupplier (); 
			break;
		
		case 2:
			Assign();
			break;

		case 3:
			SuppliersSearch();
			break;
			
		case 4:	  
			displaySuppliersList (); 
			break;
		
		case 5:
			 updateSupplierNode();
			 break;
		 
		case 6:
			deleteSupplierNode();
			break;
			
		case 7: 
			system ("cls");	  
			break;
		default: 
			cout << "\n\t\t\t\t\t\t\t  Enter Proper Option number " << endl;
}
}while(option2!=0);  
			break;
case 3:
	assignDisplay();
	break;
	
		default:
			cout<<"\n\t\t\t\t\t\t\t  Enter Proper Option Number .." << endl;
	}
	
}while(option1 !=0); //fisrt do -> displaying main menue
	return 0;
}
