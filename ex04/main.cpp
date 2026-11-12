#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv) {
    // 1. Validar argumentos
    if (argc != 4) {
        std::cerr << "Error: Se requieren 3 parametros (filename, s1, s2)." << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: s1 no puede ser una cadena vacia." << std::endl;
        return 1;
    }

    // 2. Abrir archivo original (en C++98 se usa .c_str() para el nombre)
    std::ifstream ifs(filename.c_str());
    if (!ifs.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo '" << filename << "'." << std::endl;
        return 1;
    }

    // 3. Crear archivo .replace
    std::string out_filename = filename + ".replace";
    std::ofstream ofs(out_filename.c_str());
    if (!ofs.is_open()) {
        std::cerr << "Error: No se pudo crear el archivo '" << out_filename << "'." << std::endl;
        ifs.close();
        return 1;
    }

    // 4. Leer y reemplazar (sin usar std::string::replace)
    std::string line;
    while (std::getline(ifs, line)) {
        size_t pos = 0;
        
        // Buscar s1 y reemplazarlo borrando e insertando s2
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length(); // Avanzar la posicion para no caer en bucle infinito
        }
        
        ofs << line;
        
        // Añadir salto de linea solo si no estamos al final del archivo original
        if (!ifs.eof()) {
            ofs << std::endl;
        }
    }

    // 5. Cerrar archivos
    ifs.close();
    ofs.close();

    return 0;
}