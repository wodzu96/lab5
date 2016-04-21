# Najbliżsi sąsiedzi

## Klasa `Sample`
- Stwórz klasę `Sample`, zawierającą:
    - zmienną całkowitą `label`,
    - wektor liczb zmiennoprzecinkowych `features`,
- w konstruktorze klasy `Sample` przyjmuj oba te parametry,
- stwórz też dla nich *gettery*.

## Klasa `Dataset`
- Stwórz klasę `Dataset`, zawierającą:
    - wektor obiektów klasy `Sample`,
    - metodę `push_back()`, dodającą nową próbkę do wektora:
        - metoda ta powinna sprawdzać, czy wektor `features` dla każdej z wprowadzanych próbek jest tej samej długości. 
