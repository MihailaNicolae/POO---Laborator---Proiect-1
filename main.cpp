#include <iostream>
#include <random>
#include <cstring>
using namespace std;
int op,n;
class Film
{   char denumire_film[50];
    char gen[50];
    char regizor[50];
    int rating;
public:
    char get_denumire_film(char *copie){strcpy(copie,denumire_film);}
    char get_gen(char *copie){strcpy(copie,gen);}
    char get_regizor(char *copie){strcpy(copie,regizor);}
    int get_rating(){return rating;}

    void set_denumire_film(char de[]){strcpy(denumire_film,de);}
    void set_gen(char ge[]){strcpy(gen,ge);}
    void set_regizor(char re[]){strcpy(regizor,re);}
    void set_rating(int ra){rating=ra;}

    Film(char de[]="Nume necunoscut", char ge[]="Gen necunoscut", char re[]="Regizor necunoscut", int ra=0)
    {   strcpy(denumire_film,de);
        strcpy(gen,ge);
        strcpy(regizor,re);
        rating=ra;
    }
    Film(const Film &ob1)
    {   strcpy(denumire_film,ob1.denumire_film);
        strcpy(gen,ob1.gen);
        strcpy(regizor,ob1.regizor);
        rating=ob1.rating;
    }
    ///~Film()     Stiu sa definesc si sa folosesc destructori, dar nefolosind vectori alocati dinamic inauntrul clasei, nu am nevoie de ei.


    friend ostream& operator <<(ostream &out, const Film& ob)
    {   out<<"Nume : "<<ob.denumire_film<<'\n'<<"-Gen : "<<ob.gen<<'\n'<<"-Regizor : "<<ob.regizor<<'\n'<<"-Rating : "<<ob.rating;
        return out;
    }
    friend istream& operator>>(istream& in, Film &ob)
    {   cout<<"Nume : ";
        char c;
        cin>>c;
        in.getline(ob.denumire_film, sizeof(ob.denumire_film));
        for(int i=strlen(ob.denumire_film)+1;i>=1;i--)
            ob.denumire_film[i]=ob.denumire_film[i-1];
        ob.denumire_film[0]=c;
        cout<<'\n'<<"Gen : ";
        in.getline(ob.gen,sizeof(ob.gen));
        cout<<'\n'<<"Regizor : ";
        in.getline(ob.regizor,sizeof(ob.regizor));
        cout<<'\n'<<"Rating : ";
        in>>ob.rating;
        cout<<'\n';
    }
    friend operator ==(Film const &ob1, Film const &ob2)
    {
        return ob1.rating==ob2.rating;
    }
    friend operator <(Film const &ob1, Film const &ob2)
    {
        return ob1.rating<ob2.rating;
    }
    friend operator >(Film const &ob1, Film const &ob2)
    {
        return ob1.rating>ob2.rating;
    }
};
Film *p = new Film[100];
/*void barbut()
{   int v[8];
    for(int i=1;i<=4;i++)
        v[i]=100;
    int jucatori=4;
    cout<<"Comanda secreta pentru barbut a fost activata. Tu esti jucatorul 1."<<'\n';
    cout<<"Sunt patru jucatori. Fiecare aveti 100 de lei. Incearca sa castigi cat mai mult"<<'\n';
    int sum=0;
    while(v[1]>0)
    {   cout<<"Cati lei vrei sa pariezi?"<<'\n';
        int bet=0;
        cin>>bet;
        if(bet==0)
        {   cout<<"Nu acceptam lasi la pariuri. Ai fost dat afara"<<'\n';
            return;
        }
        if(bet>v[1])
        {   bet=v[1];
            cout<<"Nu ai atatia bani. Am pariat maximul disponibil"<<'\n';
        }
        v[1]=v[1]-bet;
        sum=v[1];
        for(int i=2;i<=4;i++)
        {   ///int k=rand(1,v[i]+1);
            int k=100;
            v[i]=v[i]-k;
            sum=sum+k;
        }
        for(int i=1;i<=4;i++)
        {   if(i==1)
            {   cout<<"Ai dat: ";
            }
            else
            {   cout<<"Jucatorul "<<i<<" a dat:";

            }
            ///comparam valorile fiecaruia
            ///jucatorul i a castigat. Acum ai x lei. Reluam procesul.
        }
        cout<<"Vrei sa te retragi? Daca da..."<<'\n';
    }
    cout<<"Wow... nu e ziua ta norocoasa. Imi pare rau, dar fara bani, nu te primim. Ai fost dat afara."<<'\n';
    return;
}
*/
void patru();
void unu()
{   cout<<"Numarul de filme pe care doriti sa il adaugati este = ";
    int o;
    cin>>o;
    cin.get();
    if(o<0)
    {   cout<<"Nu putem adauga un numar negativ de filme. Ne intoarcem la selectarea optiunii"<<'\n';
        return;
    }
    if(o==0)
    {   cout<<"Nu s-a produs nicio modificare. Ne intoarcem la selectarea optiunii"<<'\n';
        return;
    }
    for(int i=1;i<=o;i++)
    {   cout<<"Filmul "<<i<<":"<<'\n';
        cin>>p[i];
        if(p[i].get_rating()>5)
        {   p[i].set_rating(5);
            cout<<"Valorile mai mari ca 5 nu se accepta. Rating-ul a fost setat la 5"<<'\n';
        }
        if(p[i].get_rating()<0)
        {   p[i].set_rating(0);
            cout<<"Valorile mai mici ca 0 nu se accepta. Rating-ul a fost setat la 5"<<'\n';
        }
    }
    n=n+o;
    return;
}
void doi()
{   if(n==0)
    {   cout<<"Nu exista filme salvate. Alegeti optiunea 1, adaugati filme, iar apoi efectuati comenzile dorite"<<'\n';
        return;
    }
    cout<<"Daca doriti redarea listei de filme, introduceti 1. Altfel, introduceti 0 sau alta valoare"<<'\n';
    int ok=0;
    cin>>ok;
    if(ok==1)
        patru();
    cout<<"Introduceti numerele de ordine ale filmelor de comparat"<<'\n';
    cout<<"Primul film:"<<'\n';
    int f1,f2;
    cin>>f1;
    cout<<"Al doilea film:"<<'\n';
    cin>>f2;
    char cop1[100],cop2[100];
    p[f1].get_denumire_film(cop1);
    p[f2].get_denumire_film(cop2);
    if(f1>n || f2>n)
    {   cout<<"Unul sau ambele filme prezinta un numar de ordine inexistent. Ne intoarcem la selectarea optiunii"<<'\n';
        return;
    }
    if(p[f1]>p[f2])
        cout<<"Filmul "<<cop1<<" este considerat mai bun decat filmul "<<cop2<<'\n';
    if(p[f1]==p[f2])
        cout<<"Filmele "<<cop1<<" si "<<cop2<<" sunt considerate la fel de bune"<<'\n';
    if(p[f1]<p[f2])
        cout<<"Filmul "<<cop1<<" este considerat mai slab decat filmul "<<cop2<<'\n';
}
void trei()
{   if(n==0)
    {   cout<<"Nu exista filme salvate. Alegeti optiunea 1, adaugati filme, iar apoi efectuati comenzile dorite"<<'\n';
        return;
    }
    cout<<"Daca doriti redarea listei de filme, introduceti 1. Altfel, introduceti 0 sau alta valoare"<<'\n';
    int ok=0;
    cin>>ok;
    if(ok==1)
        patru();
    cout<<"Numarul de ordine al filmului ce doriti a fi schimbat = "<<'\n';
    int ord;
    cin>>ord;
    if(ord>n)
    {   cout<<"Nu exista un film cu acest numar de ordine. Ne intoarcem la selectarea optiunii"<<'\n';

    }
    ok=0;
    char schimb[100];
    cout<<"Doriti sa schimbati numele filmului? Introduceti tasta 1 daca da, 0 daca nu"<<'\n';
    cin>>ok;
    if(ok==1)
    {   cout<<"Noul nume = ";
        cin.get();
        cin.getline(schimb,100);
        cout<<'\n';
        p[ord].set_denumire_film(schimb);
    }
    ok=0;
    cout<<"Doriti sa schimbati genul filmului? Introduceti tasta 1 daca da, 0 daca nu"<<'\n';
    cin>>ok;
    if(ok==1)
    {   cout<<"Noul gen = ";
        cin.get();
        cin.getline(schimb,100);
        cout<<'\n';
        p[ord].set_gen(schimb);
    }
    ok=0;
    cout<<"Doriti sa schimbati regizorul filmului? Introduceti tasta 1 daca da, 0 daca nu"<<'\n';
    cin>>ok;
    if(ok==1)
    {   cout<<"Noul regizor = ";
        cin.get();
        cin.getline(schimb,100);
        cout<<'\n';
        p[ord].set_regizor(schimb);
    }
    ok=0;
    int sch;
    cout<<"Doriti sa schimbati rating-ul filmului? Introduceti tasta 1 daca da, 0 daca nu"<<'\n';
    cin>>ok;
    if(ok==1)
    {   cout<<"Noul rating = ";
        cin>>sch;
        if(sch>5)
        {   cout<<"Valorile mai mari ca 5 nu se accepta. Rating-ul a fost setat la 5"<<'\n';
            sch=5;
        }
        if(sch<0)
        {   cout<<"Valorile mai mici ca 0 nu se accepta. Rating-ul a fost setat la 0"<<'\n';
            sch=0;
        }
        p[ord].set_rating(sch);
        cout<<'\n';
    }
    return;
}
void patru()
{   if(n==0)
    {   cout<<"Nu exista filme salvate. Alegeti optiunea 1, adaugati filme, iar apoi efectuati comenzile dorite"<<'\n';
        return;
    }
    cout<<"Acestea sunt filmele:"<<'\n';
    for(int i=1;i<=n;i++)
    {   cout<<i<<". "<<p[i]<<'\n';
        cout<<'\n';
    }
}
int main()
{   cout<<"Observatii: Rating-ul este un numar natural intre 0 si 5. Numarul de ordine al unui film este pozitia sa in lista"<<'\n'<<'\n';
    cout<<"Acesta este meniul. Mai jos sunt optiunile ce pot fi selectate:"<<'\n';
    cout<<"1. Adauga filme in lista"<<'\n';
    cout<<"2. Compara doua filme"<<'\n';
    cout<<"3. Modifica informatiile unui film"<<'\n';
    cout<<"4. Afiseaza toate filmele"<<'\n';
    cout<<"5. Opreste programul"<<'\n';
    while(op!=5)
    {
        cout<<"Optiunea dumneavoastra = ";
        cin>>op;
        cout<<'\n';
        if(op==1)
            unu();
        if(op==2)
            doi();
        if(op==3)
            trei();
        if(op==4)
            patru();
        ///if(op==7)
            ///barbut();
        if(op==5)
            break;
        if((op<1 || op>5) /*&& op!=7*/)
            cout<<"Comanda nerecunoscuta. Ne intoarcem la selectarea optiunii"<<'\n';
    }
    cout<<"Programul s-a terminat"<<'\n';
    return 0;
}
