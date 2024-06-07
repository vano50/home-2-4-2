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

    void sort(adress* addresses, int size) {
        getTown ()
            if (addresses[0] > (addresses[1])
    }
};



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