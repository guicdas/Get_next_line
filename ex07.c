#include <unistd.h>
#include <stdio.h>

void ft_print_combn(int n);

int main(){
    int n=10;

    ft_print_combn(n);
}

void ft_print_combn(int n){

    char k1, k2, k3, k4, k5, k6, k7, k8, k9, k10;

    switch(n){
        case 1:
            for(k1=48;k1<58;k1++){
                write(1, &k1, 1); 
                if(k1!=57){
                    write(1, ",\x20", 2);
                }
            }break;

        case 2:
            for(k1=48;k1<58;k1++){
                for(k2=48;k2<58;k2++){
                    if(k2>k1){
                        write(1, &k1, 1);write(1, &k2, 1); 
                        if(k1!=56){
                            write(1, ",\x20", 2);
                        }
                    }
                }
            }break;

        case 3:
            for(k1=48;k1<58;k1++){
                for(k2=48;k2<58;k2++){
                    for(k3=48;k3<58;k3++){
                        if(k2>k1 && k3>k2){
                            write(1, &k1, 1);write(1, &k2, 1);write(1, &k3, 1);
                            if(k1!=55){
                                write(1, ",\x20", 2);
                            }
                        }
                    }
                }
            }break;

        case 4:
            for(k1=48;k1<58;k1++){
                for(k2=48;k2<58;k2++){
                    for(k3=48;k3<58;k3++){
                        for(k4=48;k4<58;k4++){
                            if(k2>k1 && k3>k2 && k4>k3){
                                write(1, &k1, 1);write(1, &k2, 1);
                                write(1, &k3, 1);write(1, &k4, 1);
                                if(k1!=54){
                                    write(1, ",\x20", 2);
                                }
                            }
                        }
                    }
                }
            }break;

        case 5:
            for(k1=48;k1<58;k1++){
                for(k2=48;k2<58;k2++){
                    for(k3=48;k3<58;k3++){
                        for(k4=48;k4<58;k4++){
                            for(k5=48;k5<58;k5++){
                                if(k2>k1 && k3>k2 && k4>k3 && k5>k4){
                                    write(1, &k1, 1);write(1, &k2, 1);
                                    write(1, &k3, 1);write(1, &k4, 1);
                                    write(1, &k5, 1);
                                    if(k1!=53){
                                        write(1, ",\x20", 2);
                                    }
                                }
                            }
                        }
                    }
                }
            }break;

        case 6:
            for(k1=48;k1<58;k1++){
                for(k2=48;k2<58;k2++){
                    for(k3=48;k3<58;k3++){
                        for(k4=48;k4<58;k4++){
                            for(k5=48;k5<58;k5++){
                                for(k6=48;k6<58;k6++){
                                if(k2>k1 && k3>k2 && k4>k3 && k5>k4 && k6>k5){
                                    write(1, &k1, 1);write(1, &k2, 1);
                                    write(1, &k3, 1);write(1, &k4, 1);
                                    write(1, &k5, 1);write(1, &k6, 1);
                                    if(k1!=52){
                                        write(1, ",\x20", 2);
                                    }
                                    }
                                }
                            }
                        }
                    }
                }
            }break;

        case 7:
            for(k1=48;k1<58;k1++){
                for(k2=48;k2<58;k2++){
                    for(k3=48;k3<58;k3++){
                        for(k4=48;k4<58;k4++){
                            for(k5=48;k5<58;k5++){
                                for(k6=48;k6<58;k6++){
                                    for(k7=48;k7<58;k7++){
                                    if(k2>k1 && k3>k2 && k4>k3 && k5>k4 && k6>k5 && k7>k6){
                                    write(1, &k1, 1);write(1, &k2, 1);
                                    write(1, &k3, 1);write(1, &k4, 1);
                                    write(1, &k5, 1);write(1, &k6, 1);
                                    write(1, &k7, 1);
                                    if(k1!=51){
                                        write(1, ",\x20", 2);
                                    }
                                    }
                                    }
                                }
                            }
                        }
                    }
                }
            }break;

        case 8:
            for(k1=48;k1<58;k1++){
                for(k2=48;k2<58;k2++){
                    for(k3=48;k3<58;k3++){
                        for(k4=48;k4<58;k4++){
                            for(k5=48;k5<58;k5++){
                                for(k6=48;k6<58;k6++){
                                    for(k7=48;k7<58;k7++){
                                        for(k8=48;k8<58;k8++){
                                    if(k2>k1 && k3>k2 && k4>k3 && k5>k4 && k6>k5 && k7>k6 && k8>k7){
                                    write(1, &k1, 1);write(1, &k2, 1);
                                    write(1, &k3, 1);write(1, &k4, 1);
                                    write(1, &k5, 1);write(1, &k6, 1);
                                    write(1, &k7, 1);write(1, &k8, 1);
                                    if(k1!=50){
                                        write(1, ",\x20", 2);
                                    }
                                    }
                                    }
                                    }
                                }
                            }
                        }
                    }
                }
            }break;

        case 9:
            for(k1=48;k1<58;k1++){
                for(k2=48;k2<58;k2++){
                    for(k3=48;k3<58;k3++){
                        for(k4=48;k4<58;k4++){
                            for(k5=48;k5<58;k5++){
                                for(k6=48;k6<58;k6++){
                                    for(k7=48;k7<58;k7++){
                                        for(k8=48;k8<58;k8++){
                                            for(k9=48;k9<58;k9++){
                                    if(k2>k1 && k3>k2 && k4>k3 && k5>k4 && k6>k5 && k7>k6 && k8>k7 && k9>k8){
                                    write(1, &k1, 1);write(1, &k2, 1);
                                    write(1, &k3, 1);write(1, &k4, 1);
                                    write(1, &k5, 1);write(1, &k6, 1);
                                    write(1, &k7, 1);write(1, &k8, 1);
                                    write(1, &k9, 1);
                                    if(k1!=49){
                                        write(1, ",\x20", 2);
                                    }
                                    }
                                            }
                                    }
                                    }
                                }
                            }
                        }
                    }
                }
            }break;

        case 10:
            for(k1=48;k1<58;k1++){
                for(k2=48;k2<58;k2++){
                    for(k3=48;k3<58;k3++){
                        for(k4=48;k4<58;k4++){
                            for(k5=48;k5<58;k5++){
                                for(k6=48;k6<58;k6++){
                                    for(k7=48;k7<58;k7++){
                                        for(k8=48;k8<58;k8++){
                                            for(k9=48;k9<58;k9++){
                                                for(k10=48;k10<58;k10++){
                                    if(k2>k1 && k3>k2 && k4>k3 && k5>k4 && k6>k5 && k7>k6 && k8>k7 && k9>k8 && k10>k9){
                                    write(1, &k1, 1);write(1, &k2, 1);
                                    write(1, &k3, 1);write(1, &k4, 1);
                                    write(1, &k5, 1);write(1, &k6, 1);
                                    write(1, &k7, 1);write(1, &k8, 1);
                                    write(1, &k9, 1);write(1, &k10, 1);
                                    }
                                                }
                                            }
                                    }
                                    }
                                }
                            }
                        }
                    }
                }
            }break;

        default:break;
    }
}