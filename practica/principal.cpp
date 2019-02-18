#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <math.h>

typedef struct
{
	float x;
	float y;
} punto;

typedef struct
{
	punto centro;
	float r;
} circulo;

typedef struct
{
	punto punto1;
	punto punto2;
} Segmento;

float Distancia(punto p1, punto p2)
{
	float delta_x = p1.x - p2.x;
	float delta_y = p1.y - p2.y;
	float norma = delta_x * delta_x + delta_y * delta_y;
	float dist = sqrt(norma);
	return dist;
}

void pedir_datos_CC(circulo *cir1, circulo *cir2){
	printf("Introduzca las coordenadas del primer centro y radio\n");
	scanf("%f %f %f", &cir1->centro.x, &cir1->centro.y, &cir1->r);
	printf("Introduzca las coordenadas del segundo centro y radio\n");
	scanf("%f %f %f", &cir2->centro.x, &cir2->centro.y,&cir2->r);
}
void pedir_datos_CS(circulo *cir, Segmento *seg) {
	printf("Introduzca las coordenadas centro y radio\n");
	scanf("%f %f %f", &cir->centro.x, &cir->centro.y, &cir->r);
	printf("Introduzca los extremos del segmento\n");
	scanf("%f %f %f %f", &seg->punto1.x, &seg->punto1.y, &seg->punto2.x, &seg->punto2.y);
}
int colision(circulo cir1, circulo cir2) {
float d = Distancia(cir1.centro, cir2.centro);
return (cir2.r + cir1.r) >= d;;
}
int colision(circulo cir, Segmento seg) {
	float base = Distancia(seg.punto1, seg.punto2);
	float lado1 = Distancia(seg.punto1, cir.centro);
	float lado2 = Distancia(cir.centro, seg.punto2);
	float s = (lado1 + lado2 + base) / 2;
	float ans = sqrt(s*(s - lado1)*(s - lado2)*(s - base))*2/base;
	// comprobar colisión
	return ans<=cir.r;
}
int main(void)
{
	int i = 0;
	circulo cir1, cir2;
	Segmento seg;
	if(true){pedir_datos_CS(&cir1, &seg);
	i = colision(cir1, seg); }
	else {
	pedir_datos_CC(&cir1, &cir2);
	i = colision(cir1, cir2);
	}

	if(i) printf("Se colisionan\n");
	else printf(" NO se colisionan\n");

	while (getchar() != '\n');
	getchar();
	return 0;
}