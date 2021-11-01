#include <iostream>
#include <cstring>
using namespace std;

class Biblioteca{
int an_construire;
char adresa[20];
char *nume;
char *bibliotecar;
public:
Biblioteca(); //constructor fara parametri
Biblioteca(char[], char*, char*, int); //constructor cu parametri
Biblioteca(const Biblioteca&); //constructor de copiere
~Biblioteca(); //destructorul
void afisare() const; //afiseaza atributele clasei
void modif(char*, char*, char[],int); //modifica atributele clasei
friend char* getBibliotecar(const Biblioteca&);
friend char* getNume(const Biblioteca&);
friend int getAn(const Biblioteca&); //returneaza vechimea obiectului apelat
friend void interschimbare(Biblioteca&, Biblioteca&); //interschimba valorile dintre 2 obiecte de tip Biblioteca
};

Biblioteca::Biblioteca()
{
    an_construire=1000;
    strcpy(adresa,"");
    nume=NULL;
    bibliotecar=NULL;
    
}

Biblioteca::Biblioteca(char a[], char* n, char* b, int ac)
{
    an_construire=ac;
    strcpy(adresa,a);
    nume= new char[strlen(n) + 1];
    strcpy(nume,n);
    bibliotecar = new char[strlen(b)+1];
    strcpy(bibliotecar,b);

}
Biblioteca::Biblioteca(const Biblioteca &Ref)
{
   an_construire=Ref.an_construire;
   strcpy(adresa,Ref.adresa);
   nume=new char[strlen(Ref.nume)+1];
   strcpy(nume,Ref.nume);
   bibliotecar=new char[strlen(Ref.bibliotecar)+1];
   strcpy(bibliotecar,Ref.bibliotecar);

}
Biblioteca::~Biblioteca()
{
   delete[] nume;
   delete[] bibliotecar;
   delete[] adresa;
}
void Biblioteca::afisare() const
{ 
    cout<<"Biblioteca "<<nume;
    cout<<" a fost construita in anul "<<an_construire<<".";
    cout<<" Se situeaza la adresa:  "<<adresa<<".";
    cout<<" Bibliotecarul curent este "<<bibliotecar;
    cout<<"."<<endl;

}
void Biblioteca::modif(char* n, char* b, char a[],int ac)
{
    an_construire=ac;
    strcpy(adresa,a);
    if(nume!=NULL)
        delete[] nume;
    nume=new char[strlen(n)+1];
    strcpy(nume,n);
    if(bibliotecar!=NULL)
        delete[] bibliotecar;
    bibliotecar=new char[strlen(b)+1];
    strcpy(bibliotecar,b);
}

char* getBibliotecar(const Biblioteca& bib) 
{
    return bib.bibliotecar;
}
char* getNume(const Biblioteca& bib) 
{
    return bib.nume;
}
int getAn(const Biblioteca& In)
{
    return 2021-In.an_construire;
}
void interschimbare(Biblioteca& u1,Biblioteca& u2)
{
    Biblioteca u(u1);

    if(u1.nume !=NULL)
        delete[] u1.nume;
    u1.nume=new char[strlen(u2.nume)+1];
    strcpy(u1.nume,u2.nume);

    if(u1.bibliotecar!=NULL)
        delete[] u1.bibliotecar;
    u1.bibliotecar=new char[strlen(u2.bibliotecar)+1];
    strcpy(u1.bibliotecar,u2.bibliotecar);

    if(u2.nume !=NULL)
        delete[] u2.nume;
    u2.nume=new char[strlen(u.nume)+1];
    strcpy(u2.nume,u.nume);

    if(u2.bibliotecar!=NULL)
        delete[] u2.bibliotecar;
    u2.bibliotecar=new char[strlen(u.bibliotecar)+1];
    strcpy(u2.bibliotecar,u.bibliotecar);   
    
    u1.an_construire=u2.an_construire;
    u2.an_construire=u.an_construire;

    strcpy(u1.adresa,u2.adresa);
    strcpy(u2.adresa,u.adresa);

}

int main()
{
      cout<<endl<<"--------------Cerinta1------------------";
      cout<<endl<<endl;
      Biblioteca B1,B2("Iuliu Maniu nr.45","Gheorghe Paltanea","Iulian Conea",1978);
      B2.afisare();
      B1.modif("Liviu Rebreanu","Ana Dumitrescu","Bd. Timisoara",1899);
      B1.afisare();
      Biblioteca B3(B1);
      /* 
      B3.afisare();
      B3.~Biblioteca();
      B3.afisare();
      */
      cout<<endl<<"Dupa interschimbare:"<<endl;
      interschimbare(B1,B2);
      B1.afisare();
      B2.afisare();

    

      cout<<endl<<"--------------Cerinta2------------------";
      cout<<endl<<endl;
      Biblioteca *BD=new Biblioteca[5];
      BD[0].modif("Cazimir Otilia","Oprea Ina","Str. Preciziei nr.7", 1925);
      BD[1].modif("Eliade Mircea","Miron Ene","Bd. Magentei nr. 65",1899);
      BD[2].modif("Petrescu Camil","Ivanov Tincuta","Str. Feroviarilor",1956);
      BD[3].modif("Paltanea Gheorghe","Iulian Conea","Iuliu Maniu nr.45",1978);
      BD[4].modif("Liviu Rebreanu","Ana Dumitrescu","Bd. Timisoara",1899);
      
      cout << "Afisarea datelor fiecarei biblioteci din vector"<<endl;
	  for(int i=0;i<5;i++)
		   BD[i].afisare();


      cout<<endl<<"--------------Cerinta3------------------";
      
      for(int i=0;i<4;i++)
         for(int j=i+1;j<5;j++)
            if(strcmp(getNume(BD[i]),getNume(BD[j]))>0)
                   interschimbare(BD[i],BD[j]);
      cout <<"\n\nDupa ordonarea alfabetica in functie de nume rezulta: "<<endl;
	  for(int i=0;i<5;i++)
		   BD[i].afisare();
      



      cout<<endl<<"--------------Cerinta4------------------";
      
      int max;
      max=getAn(BD[0]);
      for(int i=1;i<5;i++)
          if(getAn(BD[i])>max)
              max=getAn(BD[i]);
      cout<<"\n\nCele mai vechi biblioteci sunt: ";
      for(int i=0;i<5;i++)
         if(max==getAn(BD[i]))
             cout<<endl<<getNume(BD[i]);
      cout<<endl;



      cout<<endl<<"--------------Cerinta5------------------";
      cout<<endl<<"Memoria se va elibera.";
      B1.~Biblioteca();
      B3.~Biblioteca();
      B2.~Biblioteca();
      delete[] BD;
      
      return 0;
}
