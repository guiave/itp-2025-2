#include <stdio.h>
#include <math.h>

int main(){
    float coor_aranha_x, coor_aranha_y, comprimento_max_teia, coor_alvos_x, coor_alvos_y, hipotenusa;
    int qtd_alvos = 0, lances = 0;
    int todos_alvos_alcancados = 1;
    
    scanf("%f", &coor_aranha_x);
    scanf("%f", &coor_aranha_y);
    scanf("%f", &comprimento_max_teia);
    scanf("%d", &qtd_alvos);
    
    for(lances = 0; lances < qtd_alvos; lances++){
        scanf("%f", &coor_alvos_x);
        scanf("%f", &coor_alvos_y);
        
        hipotenusa = sqrt(pow((coor_aranha_x - coor_alvos_x), 2) + pow((coor_aranha_y - coor_alvos_y), 2));
        
        if(hipotenusa > comprimento_max_teia){
            todos_alvos_alcancados = 0;
            break; 
        } else {
            coor_aranha_x = 2 * coor_alvos_x - coor_aranha_x;
            coor_aranha_y = 2 * coor_alvos_y - coor_aranha_y;
        }
    }
    
    if(todos_alvos_alcancados == 1){
        printf("S\n");
    } else {
        printf("N\n");
    }
    
    return 0;
}
