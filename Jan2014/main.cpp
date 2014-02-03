#include <iostream>
#include <vector>

#include <worldobject.h>
#include <person.h>
#include <relationship.h>
#include <controller.h>



using namespace std;

int main()
{
    Controller::Instance()->doThings();
/*
//Test making an object
WorldObject carrot = WorldObject("carrot");
WorldObject apple = WorldObject("apple");

//Test making a person
Person nick = Person("Nick", MALE);
Person dave = Person("Dave", MALE);
Person nikki = Person("Nikki", FEMALE);


cout<<"-------------------------\nHolding Tests\n\n";

//Test holding an item
nick.holdItem(carrot);
nick.holdItem(carrot);
nick.holdItem(apple);
nick.holdItem(carrot);
nick.holdItem(carrot);


cout<<"Nick is holding " << nick.isHolding("carrot")<<" carrot(s)"<<endl;
nick.printAllItems();
nick.dropItem("carrot",2);

cout<<"Nick is holding " << nick.isHolding("carrot")<<" carrot(s)"<<endl;
nick.printAllItems();

cout<<"-------------------------\nRelationship Tests\n\n";
Relationship rel = Relationship(&dave,&nikki);
//rel.printRelationship();

Relationship rel2 = Relationship(&nikki,&nick);
rel2.setState(Lovers,2);
//rel2.printRelationship();

//List nikki's relationships
nikki.listRelationships();

//Change a relationship and list again
//rel.setState(7,1);
//cout<<endl;
//nikki.listRelationships();


//Test all combos of relationship
/*for(int f=0;f<10;f++)
    for(int g=0;g<3;g++)
    {
        rel.setState(f,g);
        rel.printRelationship();
    }
*/


return 0;
}
