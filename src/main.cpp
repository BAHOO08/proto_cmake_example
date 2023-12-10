#include <iostream>
#include <string>

#include "proto/test.pb.h"
 
using namespace std;

int main(int argc, char* argv[])
{
    Animal message;
    //  Создаём того чего не было
    message.set_species("Cat");
    message.set_name("Tiffany");
    message.set_age(12);

    string animal_buffer;
    message.SerializeToString(&animal_buffer);
    Stoune stoun;
    stoun.set_almaz("Pepe");
    stoun.set_granit("Chermonder");
    stoun.set_fuflit(213);

    string stoune_bufer;
    stoun.SerializeToString(&stoune_bufer);

    // обновляем буфер

    Context cntxt;
    cntxt.add_data(animal_buffer);
    cntxt.add_data(stoune_bufer);

    // захотели отредачить имя у энимал
    Animal tmp_animal;
    tmp_animal.ParseFromString(cntxt.data(Fields::ANIMAL));
    tmp_animal.set_name("chupakabra");
    cout << tmp_animal.species() << '\n'
         << tmp_animal.name() << '\n'
         << tmp_animal.age();
    
    tmp_animal.SerializeToString(&animal_buffer);
    cntxt.set_data(Fields::ANIMAL,animal_buffer);
    return 0;
}