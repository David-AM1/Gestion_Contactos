#include <iostream>
#include <string>
using namespace std;

const int MAX_CONTACTOS = 100;

struct ContactoEmail{
	string nombres;
	string sexo;
	int edad;
	string telefono;
	string email;
	string nacionalidad;
};

void agregarContacto(ContactoEmail contactos[], int& cantidad){
	if(cantidad>=MAX_CONTACTOS){
		cout<<"Limite alcanzado."<<endl;
		return;
	}
	cout << "\n--- Agregar nuevo contacto ---" << endl;
    cout << "Nombres completos: ";
    getline(cin, contactos[cantidad].nombres);
    cout << "Sexo: ";
    getline(cin, contactos[cantidad].sexo);
    cout << "Edad: ";
    cin >> contactos[cantidad].edad;
    cin.ignore(); // Limpiar el buffer
    cout << "Telefono: ";
    getline(cin, contactos[cantidad].telefono);
    cout << "Email: ";
    getline(cin, contactos[cantidad].email);
    cout << "Nacionalidad: ";
    getline(cin, contactos[cantidad].nacionalidad);
    cantidad++;
    cout << "* Contacto agregado correctamente. *\n" << endl;
}

void mostrarContactos(ContactoEmail contactos[], int cantidad) {
	cout << "\n--- Listado General de Contactos ---" << endl;
	if (cantidad == 0) {
		cout << "No hay contactos registrados.\n" << endl;
		return;
	}
	for (int i = 0; i < cantidad; ++i) {
		cout << "Contacto #" << (i + 1) << ":\n";
		cout << "  Nombres: " << contactos[i].nombres << endl;
		cout << "  Sexo: " << contactos[i].sexo << endl;
		cout << "  Edad: " << contactos[i].edad << endl;
		cout << "  Telefono: " << contactos[i].telefono << endl;
		cout << "  Email: " << contactos[i].email << endl;
		cout << "  Nacionalidad: " << contactos[i].nacionalidad << endl<<endl;
	}
}

void eliminarContacto(ContactoEmail contactos[], int& cantidad) {
    if (cantidad == 0) {
        cout << "\nNo hay contactos para eliminar.\n";
        return;
    }

    cout << "\n--- Eliminar un contacto ---" << endl;
    for (int i = 0; i < cantidad; ++i) {
        cout << i + 1 << ") " << contactos[i].nombres << " - " << contactos[i].email << endl;
    }

    int indice;
    cout << "Ingrese el número del contacto a eliminar: ";
    cin >> indice;
    cin.ignore();

    if (indice < 1 || indice > cantidad) {
        cout << "Número inválido.\n";
        return;
    }

    // Eliminar moviendo los contactos posteriores hacia la izquierda
    for (int i = indice - 1; i < cantidad - 1; ++i) {
        contactos[i] = contactos[i + 1];
    }

    cantidad--;
    cout << "* Contacto eliminado correctamente. *\n";
}

string obtenerServidorEmail(const string& email) {
    string servidor = "";
    bool arrobaEncontrada = false;

    for (int i = 0; i < email.length(); i++) {
        if (arrobaEncontrada) {
            servidor += email[i];
        }
        if (email[i] == '@') {
            arrobaEncontrada = true;
        }
    }

    return servidor;
}

void ordenarPorServidor(ContactoEmail contactos[], int cantidad) {
    for (int i = 0; i < cantidad - 1; ++i) {
        for (int j = 0; j < cantidad - i - 1; ++j) {
            string servidorA = obtenerServidorEmail(contactos[j].email);
            string servidorB = obtenerServidorEmail(contactos[j + 1].email);

            if (servidorA > servidorB) {
                ContactoEmail temp = contactos[j];
                contactos[j] = contactos[j + 1];
                contactos[j + 1] = temp;
            }
        }
    }
}

void mostrarContactosPorServidor(ContactoEmail contactos[], int cantidad) {
    if (cantidad == 0) {
        cout << "\nNo hay contactos registrados.\n";
        return;
    }
    ordenarPorServidor(contactos, cantidad);
    string servidorAnterior = "";
    for (int i = 0; i < cantidad; ++i) {
        string servidor = obtenerServidorEmail(contactos[i].email);
        if (servidor != servidorAnterior) {
            cout << "\n--- Contactos con servidor: " << servidor << " ---\n";
            servidorAnterior = servidor;
        }
        cout << "  " << contactos[i].nombres << " - " << contactos[i].email << endl;
    }
}

int main(){
	ContactoEmail contactos[MAX_CONTACTOS];
    int cantidadContactos = 0;
	char opcion;
	while(opcion!='e'){
		cout<<"\n=== GESTION DE CONTACTOS ==="<<endl;
		cout<<"a) Agregar un contacto"<<endl;
		cout<<"b) Eliminar un contacto"<<endl;
		cout<<"c) Mostrar listado general de contactos registrados hasta ese momento."<<endl; 
		cout<<"d) Mostrar listado de contactos existentes, ordenado por servidor de correo de las cuentas."<<endl;
		cout<<"e) Salir del programa"<<endl;
		cout<<">>Seleccione una opcion (segun la letra): ";
		cin>>opcion;
		cin.ignore();
		switch (opcion){
			case 'a':
				agregarContacto(contactos, cantidadContactos);
				break;
			case 'b':
  				eliminarContacto(contactos, cantidadContactos);
  				break;
			case 'c':
                mostrarContactos(contactos, cantidadContactos);
                break;
            case 'd':
			    mostrarContactosPorServidor(contactos, cantidadContactos);
			    break;
			case 'e':
				cout<<"Saliento del programa."<<endl;
				return 0;
			default:
				cout<<"Opcion incorrecta."<<endl;
				break;
		}
	}
	return 0;
}
