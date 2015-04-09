#ifndef TACHE_H
#define TACHE_H


class Tache {

 public :
    Tache();
   // virtual void run ();
    void setStatus (bool );
    bool getStatus (void );

 protected :
   
    bool status_;
};

// Ici nous avons les trois taches que le robot devra executer

class Tache1 : public Tache {

 public :
   
    void run () ;
   
};


class Tache2 : public Tache {

 public :
   
    void run () ;
   
};


class Tache3 : public Tache {

 public :
   
    void run () ;
   
};
#endif
