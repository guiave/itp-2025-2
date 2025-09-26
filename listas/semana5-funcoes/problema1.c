#include <stdio.h>

void convertTo24h(int hour, int minute, char period) {
    if (period == 'A' || period == 'a') {
        if (hour == 12) hour = 0;
    } else {
        if (hour != 12) hour += 12;
    }
    printf("%02d:%02d\n", hour, minute);
}

void convertTo12h(int hour, int minute) {
    char period;
    int displayHour = hour;
    
    if (hour == 0) {
        displayHour = 12;
        period = 'A';
    } else if (hour < 12) {
        period = 'A';
    } else if (hour == 12) {
        period = 'P';
    } else {
        displayHour = hour - 12;
        period = 'P';
    }
    
    printf("%02d:%02d %cM\n", displayHour, minute, period);
}

void calculateRounds(int startHour, int startMinute, int intervalMinutes, int totalHours) {
    int currentHour = startHour;
    int currentMinute = startMinute;
    int totalMinutes = totalHours * 60;
    int elapsedMinutes = 0;
    
    printf("Horários das rondas:\n");
    printf("Formato 24h    Formato 12h\n");
    printf("----------     -----------\n");
    
    while (elapsedMinutes <= totalMinutes) {
        printf("%02d:%02d          ", currentHour, currentMinute);
        
        convertTo12h(currentHour, currentMinute);
        
        currentMinute += intervalMinutes;
        if (currentMinute >= 60) {
            currentHour += currentMinute / 60;
            currentMinute = currentMinute % 60;
            if (currentHour >= 24) {
                currentHour = currentHour % 24;
            }
        }
        
        elapsedMinutes += intervalMinutes;
    }
}

int main() {
    int choice;
    
    printf("SISTEMA DE ROUNDS POLICIAIS\n\n");
    printf("1. Converter horário 12h para 24h\n");
    printf("2. Converter horário 24h para 12h\n");
    printf("3. Calcular horários de rounds\n");
    printf("0. Sair\n");
    
    while (1) {
        printf("\nEscolha uma opção: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                int hour, minute;
                char period;
                printf("Digite o horário no formato 12h (ex: 2 30 P para 2:30 PM): ");
                scanf("%d %d %c", &hour, &minute, &period);
                printf("Horário em formato 24h: ");
                convertTo24h(hour, minute, period);
                break;
            }
            
            case 2: {
                int hour, minute;
                printf("Digite o horário no formato 24h (ex: 14 30 para 14:30): ");
                scanf("%d %d", &hour, &minute);
                printf("Horário em formato 12h: ");
                convertTo12h(hour, minute);
                break;
            }
            
            case 3: {
                int startHour, startMinute, interval, duration;
                printf("Digite o horário de início (formato 24h - ex: 10 15): ");
                scanf("%d %d", &startHour, &startMinute);
                printf("Digite o intervalo entre rounds (em minutos): ");
                scanf("%d", &interval);
                printf("Digite a duração total do patrulhamento (em horas): ");
                scanf("%d", &duration);
                
                printf("\n");
                calculateRounds(startHour, startMinute, interval, duration);
                break;
            }
            
            case 0:
                printf("Programa encerrado.\n");
                return 0;
                
            default:
                printf("Opção inválida!\n");
        }
    }
    
    return 0;
}