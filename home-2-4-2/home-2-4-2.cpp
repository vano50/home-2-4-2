#include <iostream>
#include <string>
#include <fstream>

class adress {
private:
    std::string town;
    std::string street;
    int house;
    int room;

public:
    std::string getTown() { return town; }

    std::string conclusion() const {
        return town + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(room) + "\n";
    }


    void readFromStream(std::istream& in) {
        in >> town >> street >> house >> room;
    }

    
};

void sort(adress* adressMassiv, int size) {
   
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            if (adressMassiv[j].getTown() > adressMassiv[j + 1].getTown()) {
                std::swap(adressMassiv[j], adressMassiv[j + 1]);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::ifstream in_file("in.txt");
    std::ofstream out_file("out.txt");

    if (!in_file.is_open()) {
        std::cout << "Файл не открылся!";
        return 1;
    }
    int vMassiv;
    in_file >> vMassiv;
    out_file << vMassiv << std::endl;
    adress* adressMassiv = new adress[vMassiv];

    for (int q = 0; q < vMassiv; ++q) {
        adressMassiv[q].readFromStream(in_file);
    }

    sort(adressMassiv, vMassiv);

    for (int q = 0; q < vMassiv; ++q) {
        out_file << adressMassiv[q].conclusion();
    }

    delete[] adressMassiv;

    return 0;
}