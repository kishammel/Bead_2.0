#include "graphics.hpp"
#include "widget.h"
#include "szamlalo.h"
#include "legordulo.h"
#include<iostream>
#include<vector>
#include<random>
#include<cmath>
#include<cstdlib>
#include<fstream>

using namespace genv;




int main()
{
    gout.open(400,400);

    event ev;

    std::vector<widget*>widgetek;
    legordulo * l1 = new legordulo(60,80,100,100);
    l1->hozzaad("PINK");
    l1->hozzaad("Piros");
    l1->hozzaad("Kék");
    l1->hozzaad("Zöld");
    l1->hozzaad("Sárga");




   legordulo * l2 = new legordulo(60,80,300,100);
  l2->hozzaad("PINK");
   l2->hozzaad("Piros");
    l2->hozzaad("Kék");
    l2->hozzaad("Zöld");
    l2->hozzaad("Sárga");


  widgetek.push_back(l1);
  widgetek.push_back(l2);
   widgetek.push_back(new szamlalo(70,50,195,100, 15, 30));
 std::ofstream outfile;
outfile.open("eredmenyek.txt");

    while(gin >> ev)
    {




        for(int i=0; i<widgetek.size(); ++i)
        {

            {

                widgetek[i]->event (ev);
                widgetek[i]->draw();




              /*  for(int j=0; j<widgetek.size(); ++j)
                {
                    outfile<< widgetek[j]->wertek()<<",";
                }*/



            }
        }


gout<<refresh;
    }
    outfile.close();
    for (int i = 0; i < widgetek.size(); ++i){
        delete widgetek[i];
    }
    return 0;
}
