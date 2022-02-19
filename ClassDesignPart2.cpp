#include <iostream>
#include <string>

#include "Section A.h"
#include "Section B.h"
#include "Section C.h"


using namespace std;


//Testing URL = "https://example.com/some/path/to/file.txt";
const string test = "https://example.com/some/path/to/file.txt";
int main() {
	cout << "Section A" << endl;
	//Create URL object
	//input URL as (const) string into it
	const URL myURL(test);

	
	

	//outputs parts of the URL
	
	//printURL(myURL); 
	cout << "Overloaded \n" << myURL << endl;


	cout << "\n \nSection B" << endl;

	//Create ImageMetadata object
	imageMetadata pictureOfAHorse("Horse");

	//add inputs
	
	pictureOfAHorse.setImageType("PNG");
	pictureOfAHorse.setDateCreated(5, 2, 1910);
	pictureOfAHorse.setSize(5000.0);
	pictureOfAHorse.setAuthorName("Frank");
	pictureOfAHorse.setDimensions(400, 200);
	pictureOfAHorse.setApertureSize(5);
	pictureOfAHorse.setExposureTime(8);
	pictureOfAHorse.setISO(400);
	pictureOfAHorse.setFlashEnabled(false);



	//outputs
	//display(pictureOfAHorse);
	cout << "Overloaded \n" << pictureOfAHorse << endl;


	cout << "\n \nSection C" << endl;

	store hallmart;
	order cart;


	//create item
	//         name, ID, Price, Quantity
	item Bread("Bread", 1, 10.0, 50);
	
	item Corn("Corn", 2, 4.0, 100);
	

	//add item and position is set with ID
	hallmart.addStorage(Bread);
	hallmart.addStorage(Corn);


	//hallmart.displayStorage();
	cout << "Overloaded: \n" << hallmart << endl;
	

	//2 bread for $10.0 at position 0 (probably a better way to do this)
	cart.addList(Bread, 2, 0);

	//10 Corn for $4.0 
	cart.addList(Corn, 10, 1);


	//process Order
	hallmart.processOrder(cart);


	//should be 60
	cout << "Total cost: " << cart.getPrice() << endl;


	//show change
	cout << "New storage: \n" << hallmart << endl;
}
