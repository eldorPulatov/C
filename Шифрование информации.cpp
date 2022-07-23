#include <iostream>
using namespace std;

class Shifr{
    char* a;
    int length;
public:
    Shifr();
    Shifr(int dlina);
    ~Shifr();
    void ROT13();
    void A1Z26();
    void Decoding_A1Z26(int* &shifr, const int &count_text);
    friend ostream& operator<<(ostream &out, Shifr &m);
};

Shifr::Shifr(){
    length = 5;
    a = new char [length];
    for(int i = 0; i < length; ++i){
        a[i] = '1';
    }
}

Shifr::Shifr(int dlina){
    length = dlina;
    a = new char [length];
    cin.getline(a, length);
    
}

Shifr::~Shifr(){
    delete[] a;
}

void Shifr::ROT13(){
    char b[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char c[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char d[] = {'n','o','p','q','r','s','t','u','v','w','x','y','z','a','b','c','d','e','f','g','h','i','j','k','l','m'};
    for(int i = 0; a[i] != '\0' ; ++i){
        for(int j = 0; b[j] != '\0'; ++j){
            if(a[i] == b[j]){
                a[i] = c[j];
            }
        }
    }
    for(int i = 0; a[i] != '\0' ; ++i){
        for(int j = 0; c[j] != '\0'; ++j){
            if(a[i] == c[j]){
                a[i] = d[j];
            }
        }
    }
}


int count_text = 0;
int* shifr;
void Shifr::A1Z26(){
    for(int i = 0; a[i] != '\0'; ++i)
        ++count_text;
    shifr = new int [count_text];
    char b[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char c[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    for(int i = 0; a[i] != '\0' ; ++i){
        for(int j = 0; b[j] != '\0'; ++j){
            if(a[i] == c[j]){
                a[i] = b[j];
            }
        }
    }
    
    for(int i = 0; a[i] != '\0'; ++i){
        for(int j = 0; b[j] != '\0'; ++j){
            if(a[i] == b[j]){
                shifr[i] = j;
            }
        }
    }
    for(int i = 0; i < count_text; ++i){
        cout << shifr[i] << " ";
    }
}

void Shifr::Decoding_A1Z26(int* &shifr, const int &count_text){
    char b[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for(int i = 0; i < count_text; ++i){
        for(int j = 0; b[j] != '\0'; ++j){
            if(j == shifr[i]){
                a[i] = b[j];
            }
        }
    }
}

ostream& operator<<(ostream &out, Shifr &shifr){
    out << shifr.a;
    return out;
}

int main()
{
    Shifr a(80);
    cout << "ROT13: ";
    a.ROT13();
    cout << a << endl;
    a.ROT13();
    cout << "Decoding_ROT13: ";
    cout << a << endl;
    
    cout << "A1Z26: ";
    a.A1Z26();
    cout << endl;
    
    cout << "Decoding_A1Z26: ";
    a.Decoding_A1Z26(shifr, count_text);
    cout << a;

    delete[] shifr;
}