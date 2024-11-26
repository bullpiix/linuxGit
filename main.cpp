
#include <iostream>
#include <cstdlib> // Para std::system
#include <unistd.h> // Para chdir

int main() {
    std::string path;
    std::string dirw;
    std::cout << "Carpeta de trabajo: ";
    std::cin >> dirw;

    // Cambiar el directorio usando chdir
    if (chdir(dirw.c_str()) != 0) {
        std::cerr << "Error: No se pudo mover al directorio.. :( " << dirw << "\n";
        return 1;
    }
    std::cout << "Movido al directorio: " << dirw << ".. :)\n";

    // Inicializar Git en el nuevo directorio
    std::string setCmd = "git init";
    int gogit = std::system(setCmd.c_str());
    if (gogit == 0) {
        std::cout << "ok-- Repositorio Git inicializado correctamente.. :)\n";
    } else {
        std::cerr << "Error: Falló el comando.. :( '" << setCmd << "'\n";
        return 1;
    }
    
    std::cout << "link repositorio GitHub: " << std::endl;
    std::cin >> path;
    setCmd ="git remote add origin "+path+".git";
    gogit = std :: system (setCmd.c_str());
    if (gogit ==0){
        std::cout << "ok-- add link GitHub  :)"<< std:: endl;
    }else {
        std::cerr << "Error: Fallo el comando :("<< std:: endl;
        return 1;
    }
    std::string nRama;
    std::cout << "name new Rama : " << std::endl;
    std::cin >> nRama;
    setCmd = "git checkout -b "+nRama;
    gogit = std :: system (setCmd.c_str());
    if (gogit ==0){
        std::cout << "ok-- new Rama creada--  :)"<< std:: endl;
    }else {
        std::cerr << "Error: Fallo el comando :("<< std:: endl;
        return 1;
    }

    std::cout << "name file : " << std::endl;
    std::cin >> path;
    setCmd ="git add "+dirw +"/"+path;
    gogit = std :: system (setCmd.c_str());
    if (gogit ==0){
        std::cout << "ok--  :)"<< std:: endl;
    }else {
        std::cerr << "Error: Fallo el comando :("<< std:: endl;
        return 1;
    }
    std::cout << "name commit : " << std::endl;
    std::cin >> path;
    setCmd ="git commit -m \""+path+"\"";
    gogit = std :: system (setCmd.c_str());
    if (gogit ==0){
        std::cout << "ok-- commit :)"<< std:: endl;
    }else {
        std::cerr << "Error: Fallo el comando :("<< std:: endl;
        return 1;
    }
    std::cout << "final Push press \"Enter\"" << std::endl;  
    setCmd = "git push -u origin "+nRama;
    gogit = std :: system (setCmd.c_str());
    if (gogit ==0){
        std::cout << "ok--- push GitHub --- bye :)"<< std:: endl;
    }else {
        std::cerr << "Error: Fallo el comando :("<< std:: endl;
        return 1;
    }

    return 0;
}

