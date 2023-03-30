#include <iostream>
using namespace std;

const char *nombre_archivo = "archivo.dat";
    struct Estudiante
    {
        int codigo;
        char nombres[50];
        char apellidos[50];
        int telefono;

    };
    void Crear();
    void Leer();
    void actualizar();
    void borrar();

int main(int argc, char const *argv[])
{
    Leer();
    //Crear();
    //actualizar(;
    borrar();

    system("pause");

}
void Crear(){
    FILE* archivo = fopen(nombre_archivo, "a+b");
    char res;
    Estudiante estudiante;
    do
    {
        fflush(stdin);
        cout<<"ingrese codigo";
        cin>>estudiante.codigo;
        cin.ignore();
        cout<<"ingrese nombre";
        cin.getline(estudiante.nombres,50);
         cout<<"ingrese Apellido";
        cin.getline(estudiante.apellidos,50);
         cout<<"ingrese Telefono";
         cin>>estudiante.telefono;
            fwrite(&estudiante,sizeof(Estudiante),1,archivo);
            cout<<"Desea ingresar  otro estudiante";
            cin>>res;

    } while (res=='S' ||res=='s' );
    
    fclose(archivo);
  
}
void Leer(){
    system("cls");
    FILE* archivo = fopen(nombre_archivo,"rb");
    if (!archivo)
    {
        archivo=fopen(nombre_archivo, "w+b");
       }
        Estudiante estudiante;
        int id=0;
        fread(&estudiante,sizeof(Estudiante),1, archivo);
        cout<<"_________________________________________"<<endl;
        cout<<"ID"<<"|"<<"codigo"<<"|"<<"nombre"<<"|"<<"apellidos"<<"|"<<"telefono"<<endl;
        do
        {
            cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.telefono<<endl;
            fread(&estudiante,sizeof(Estudiante),1, archivo);
            id+=1;
        } while (feof(archivo)==0);
        fclose(archivo);
        

    
       }

void Actualizar(){
	
	FILE* archivo = fopen(nombre_archivo,"r+b"); 
	Estudiante estudiante;
	int id=0;
	cout<<"Ingrese el ID que desea Modificar:";
	cin>>id;
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
		cout<<"Ingrese Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		
		cout<<"Ingrese Nombres:";
		cin.getline(estudiante.nombres,50);
		
		cout<<"Ingrese Apellidos:";
		cin.getline(estudiante.apellidos,50);
		
		cout<<"Ingrese Telefono:";
		cin>>estudiante.telefono;
		
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
	
	
	fclose(archivo);
	Leer();
}
void Borrar(){
	const char *nombre_archivo_temp = "archivo_temp.dat";
	FILE* archivo_temp = fopen(nombre_archivo_temp,"w+b");
	FILE* archivo = fopen(nombre_archivo,"rb");
	Estudiante estudiante;
	int id=0,id_n=0;
	cout<<"Ingrese el ID a eliminar:";
	cin>>id;
	while(fread(&estudiante,sizeof(Estudiante),1,archivo)){
		if (id_n !=id ){
			fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp);
		}
		id_n++;
	}
	fclose(archivo);
	fclose(archivo_temp);
	
	archivo_temp = fopen(nombre_archivo_temp,"rb");
	archivo = fopen(nombre_archivo,"wb");
	while(fread(&estudiante,sizeof(Estudiante),1,archivo_temp)){
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		
	}
		fclose(archivo);
	fclose(archivo_temp);
	Leer();
}