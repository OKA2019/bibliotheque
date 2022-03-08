
/* CREATION DE LA BASE DE DONNÉES "bibliotheque" */

/* TABLE DES Adherents "Personne qui emptruntes ls livres "*/
create table Adherents(
    num_Adh varchar(30) primary key,
    nom varchar(30) not null,
    prenoms varchar(100) not null,
    age integer(03) not null, 
    contact integer(10),
    residence varchar(30),
    sexe tinyint(1),
);


/* TABLE DES Livres "Livres de la bibliotheques"*/
create table livres(
    num_liv varchar(30) primary key,
    titre varchar(50) not null,
    auteur varchar(100) not null,
    mot_cle varchar(100),
    date_par int(4),
    nb_exem integer(11)
);


/* TABLE DES Livres "Livres de la bibliotheques"*/
create table Emprunt(
    num_emp integer(11) UNSIGNED PRIMARY KEY AUTO_INCREMENT, 
    date_sor int(11),
    date_ret int(11), 
    date_lim int(11),
    iden_Adh varchar(30),
    iden_liv varchar(30),
    statut tinyint(1) NOT NULL DEFAULT 0,
    FOREIGN KEY(iden_Adh) REFERENCES Adherents(num_Adh),
    FOREIGN KEY(iden_liv) REFERENCES livres(num_liv)
)ENGINE = INNODB;
