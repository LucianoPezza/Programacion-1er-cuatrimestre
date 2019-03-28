

int saludar()
{
printf("hello world");
return 0;
}


int dividir(int numero)
{
    int respuesta;
    int resultado;
    respuesta = esDistintoAcero(numero);
    if( respuesta ==1)
    {
      resultado = numero/2;
    }

    return respuesta;
}

int esDistintoAcero(int numero)
{
    if(numero !=0)
    {
        return 1;
    }
    return 0;
}
int factorear(int numero){

    int respuesta;
    if(numero == 1)
    {
        return 1;
    }
    respuesta=numero*factorear(numero-1);
    return respuesta;*/

