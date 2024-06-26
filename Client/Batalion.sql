use BATALIOANE

if OBJECT_ID('Studenti', 'u') is not null
	drop table Studenti
go
CREATE TABLE Studenti
(
Username varchar(30),
Parola varchar(30),
SerieArma varchar(30),

Nume varchar(30),
Prenume varchar(30),

Companie int,
Pluton int,
Incazarmat bit,

NrTelefon varchar(11),
Adresa varchar(100),
GrupaStudii varchar(5)
)

INSERT Studenti (Nume, Prenume, SerieArma) VALUES
('Aionesa', 'Denisa', '100'),
('Balteanu', 'Andrei', '111'),
('Buzica', 'Marius', '110'),
('Cotoban', 'Giulio', '110'),
('Ion', 'Alexandru', '110'),
('Lesenciuc', 'Andrei', '110'),
('Livadariu', 'Mihnea', '110'),
('Manole', 'Alexandru', '110'),
('Martin', 'Andrei', '110'),
('Miron', 'Radu', '110'),
('Mitroescu', 'David', '110'),
('Nagirdu', 'Alexandros', '110'),
('Nechita', 'Camelia', '100'),
('Obogeanu', 'Andrei', '111'),
('Olariu', 'Razvan', '110'),
('Pasarica', 'Mihaela', '100'),
('Popescu', 'Andrei', '110'),
('Rascol', 'Andrei', '110'),
('Rus', 'Denis', '110'),
('Toderoiu', 'Mihai', '111'),
('Trefil', 'Claudiu', '111'),
('Vasile', 'Danut', '110'),
('Vasiluta', 'Robert', '111'),
('Vetisan', 'Robert', '110'),
('Zobrinschi', 'Andrei', '110'),
('Lozniceriu', 'Alexandru', '210'),
('Buzoianu', 'Dorian', '210'),
('Fagaras', 'Robert', '210'),
('Antemir', 'David', '210'),
('Balasea', 'Cristian', '210'),
('Boghici', 'Kevin', '210'),
('Chelmagan', 'Gabriela', '200'),
('Neagu', 'Nicoleta', '201'),
('Pamint', 'Dennis', '211'),
('Ionescu', 'Horatiu', '210'),
('Pinu', 'Mihaita', '210'),
('Ion', 'Alexandru', '210'),
('Chitu', 'Mihai', '210'),
('Gainusei', 'Suzana', '200'),
('Chirica', 'Diana', '201'),
('Vancica', 'Mario', '210'),
('Moldoveanu', 'Marian', '210'),
('Ciuculin', 'Tiberiu', '210'),
('Ciurea', 'Andrei', '210'),
('Bruma', 'George', '210'),
('Radulescu', 'Andreea', '200'),
('Apahidean', 'Luca', '311'),
('Aionesei', 'Marian', '310'),
('Borcila', 'Vasile', '310'),
('Buontempo', 'Raul', '310'),
('Ceresanu', 'Cosmin', '310'),
('Cojocaru', 'Dragos', '310'),
('Chivu', 'Bogdan', '310'),
('Dinu', 'Liviu', '310'),
('Filip', 'Larisa', '300'),
('Forminte', 'Andreea', '300'),
('Gaitan', 'Nicolai', '310'),
('Gatan', 'Ema', '300'),
('Iancu', 'Vlad', '310'),
('Lepadatu', 'Tudor', '310'),
('Leu', 'Catalin', '310'),
('Moldovan', 'Andrei', '311'),
('Pontos', 'Alexandru', '310'),
('Stanciu', 'Razvan', '310'),
('Stoica', 'Cristian', '310'),
('Sandru', 'Laura', '300'),
('Steopoae', 'Anamaria', '300'),
('Stir', 'Catalin', '310'),
('Vaduva', 'Marius', '310'),
('Andone', 'Daria', '400'),
('Andrei', 'Diana', '400'),
('Bicoiu', 'Ionut', '410'),
('Condur', 'Florentin', '410'),
('Costan', 'Rares', '410'),
('Dragomir', 'Alexia', '400'),
('Dumitru', 'Estera', '400'),
('Florea', 'Cristian', '410'),
('Gingu', 'Tavi', '410'),
('Heasca', 'Antonio', '410'),
('Hutuleac', 'Andreea', '400'),
('Milea', 'Alexandru', '410'),
('Mitrache', 'Andreea', '400'),
('Negrea', 'Andrei', '410'),
('Pilipautanu', 'Tudor', '410'),
('Rosca', 'George', '410'),
('Shanab', 'Bianca', '400'),
('Sirbu', 'Bianca', '400'),
('Sofianu', 'Gabriela', '400'),
('Stan', 'Sabin', '410'),
('Stancu', 'David', '410'),
('Tatar', 'Ioan', '410'),
('Duca', 'Mara', '500'),
('Rus', 'Emanuel', '510'),
('Vladuceanu', 'Tudor', '510'),
('Oprea', 'Laurentiu', '510'),
('Ciobanu', 'Bianca', '500'),
('Popovici', 'Raluca', '500'),
('Negoescu', 'Camelia', '500'),
('Axinescu', 'Valentin', '510'),
('Gruia', 'Stefan', '510'),
('Pila', 'Alexandru', '510'),
('Meclea', 'Bogdan', '510'),
('Andrei', 'Roxana', '500'),
('Tanase', 'Doru', '510'),
('Braila', 'George', '510'),
('Badea', 'Alexandru', '510'),
('Aldea', 'Alexandra', '500'),
('Turcanu', 'Iuliana', '500'),
('Lupescu', 'Cristina', '500'),
('Acosti', 'Claudiu', '511'),
('Ivescu', 'Mircea', '511'),
('Rusu', 'Calin', '511'),
('Grosu', 'Razvan', '511')


INSERT Studenti (Username, Parola) VALUES
('primul', 'parola1'),
('aldoilea', 'parola2'),
('altreilea', 'parola3');