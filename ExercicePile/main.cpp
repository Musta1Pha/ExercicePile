#include <iostream>

using namespace std;

 class cellule{
   private:
      int data;
   public:
      cellule* next;
      cellule(int data);
      void Afficher1() const;
 };

  cellule::cellule(int data){
    this->data = data;
    this->next = NULL;
 }

 void cellule::Afficher1() const{
    cout<<this->data<<endl;
 }

 class Pile{
   private:
      cellule* Sommet;
   public:
      Pile();
      void Empiler(int data);
      void Depiler();
      bool PileVide();
      void ValeurSommet() const;
      void Afficher() const;

 };

  Pile::Pile(){
      this->Sommet = NULL;
  }

  void Pile::Empiler(int data){
     cellule* temp;
     cellule *b = new cellule(data);
     temp = this->Sommet;
     this->Sommet = b;
     b->next = temp;

  }

  void Pile::Depiler(){
     cellule* temp;
     if(this->Sommet != NULL){
     temp = this->Sommet;
     this->Sommet = this->Sommet->next;
     delete temp;
  }
  }

  void Pile::ValeurSommet() const{
     this->Sommet->Afficher1();

  }

  void Pile::Afficher() const{
     cellule* temp;
     temp = this->Sommet;
     while(temp!=NULL){
      temp->Afficher1();
      temp = temp->next;
  }
  }

  bool Pile::PileVide(){
    return this->Sommet==NULL;
  }

int main()
{
    Pile p;

     p.Empiler(1);
     p.Empiler(2);
     p.Empiler(3);

     p.Afficher();

     cout<<"Le Sommet est : "<<endl;
     p.ValeurSommet();

     p.Depiler();

     cout<<"Le Sommet est : "<<endl;
     p.ValeurSommet();

     cout<<p.PileVide();

    return 0;
}
