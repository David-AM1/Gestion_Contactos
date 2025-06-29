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

int main(){
	ContactoEmail contactos[MAX_CONTACTOS];
    int cantidadContactos = 0;
	char opcion;
	while(opcion!='e'){
		cout<<"\n=== GESTION DE CONTACTOS ==="<<endl;
		cout<<"a) Agregar un contacto"<<endl;
		cout<<"b) Eliminar un contacto"<<endl;
		cout<<"c) Mostrar listado general de contactos registrados hasta ese momento."<<endl; 
		cout<<"d) Mostrar listado de contactos existentes"<<endl;
		cout<<"e) Salir del programa"<<endl;
		cout<<">>Seleccione una opcion (segun la letra): ";
		cin>>opcion;
		cin.ignore();
		switch (opcion){
			case 'a':
				agregarContacto(contactos, cantidadContactos);
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