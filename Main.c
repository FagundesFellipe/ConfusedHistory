#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h> ///para perguntar antes de fechar
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <locale.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>

int LARGURA;
int ALTURA ;

const double FPS = 60.0;

typedef struct{
        char nome[51];
        char cidade [41];
        //int idade();
}Treg_cadastro;
typedef FILE * Tarq_cadastro;

void executarMenu();
void desenharMenu(bool, bool, bool, int);

void executarComoJogar();
void desenharComoJogar();

void cadastro();
void desenharCadastro();

void executarAviso();
void desenharAviso();

void executarParte1();
void desenharParte1(bool, bool);

void executuarParte2();
void desenharParte2(bool, bool);

void excutarParte3();
void desenharParte3();

void executarParte3_1();
void desenharParte3_1(bool, bool);

void executarParte4(bool);
void desenharParte4();

void executarParte5(bool);
void desenharParte5(bool, bool, int);

void executarParte6_isqueiro();
void desenharParte6_isqueiro();

void executarParte6_N_isqueiro();
void desenharParte6_N_isqueiro();

void executarParte7();
void desenharParte7(bool, bool);


void executarParte8();
void desenharParte8(bool, bool, bool);

void executarParte8D();
void desenharParte8D(bool, bool);

void executarParte8E();
void desenharParte8E(bool, bool);

void executarParte8T();
void desenharParte8T(bool, bool);

void executarParte9D();
void desenharParte9D();

void executarParte9_1D();
void desenharParte9_1D();

void executarParte9E();
void desenharParte9E(bool, bool);

void executarParte9_1E();
void desenharParte9_1E();

void executarParte10D();
void desenharParte10D(bool, bool);

void executarParte10_1();
void desenharParte10_1();

void executarParte11();
void desenharParte11();

void executarParte11_1();
void desenharParte11_1();

void executarParte12();
void desenharParte12(bool, bool);

void executarParte13();
void desenharparte13(bool, bool);

void executarParte14();
void desenharParte14(bool, bool);

void executarParte14_abrirporta();
void desenharParte14_abrirporta(bool, bool);

void executarParte14_seguirfrente();
void desenharparte14_seguirfrente();

void executarParte14_abrirporta1();
void desenharParte14_abrirporta1();

void executarParte14_1();
void desenharParte14_1();

void executarParte15();
void desenharParte15();

void executarParte15_1();
void desenharParte15_1();

void executarParte16();
void desenharParte16(bool, bool);

void executarParte17();
void desenharParte17();

void executarParte17_1();
void desenharParte17_1();

void executarFIM();
void desenharFIM();

void executarCreditos();
void desenharCreditos();


int main()
{
    setlocale(LC_ALL,"");
    ALLEGRO_DISPLAY *janela;
    ALLEGRO_DISPLAY_MODE dimensao;

    al_init();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();
    al_install_mouse();
    //al_set_system_mouse_cursor(janela,ALLEGRO_SYSTEM_MOUSE_CURSOR_DEFAULT);
    al_install_keyboard();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(3);

    al_get_display_mode(al_get_num_display_modes() -1, &dimensao);
    al_set_new_display_flags(ALLEGRO_FULLSCREEN);
    janela = al_create_display(dimensao.width, dimensao.height);
    al_set_window_title(janela,"Confused History" );
    LARGURA = dimensao.width;
    ALTURA = dimensao.height;

    executarMenu();

    al_destroy_display(janela);

    return 0;
}

void executarMenu()
{
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_BITMAP * ico = NULL;
    bool sair = false;
    bool sel1 = false, sel2 = false,sel3 = false;
    int x_imagem = 0;
    double tempo_ini = 0, tempo_fin = 0;
    ALLEGRO_AUDIO_STREAM * musica = NULL;

    fila_eventos = al_create_event_queue();

    musica = al_load_audio_stream("recursos/menu.ogg",4,1024);
    ico = al_load_bitmap("recursos/menu1.png");

    al_set_audio_stream_playmode(musica,ALLEGRO_PLAYMODE_LOOP);
    al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());

    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());

    al_set_audio_stream_playing(musica,true);

    while(!sair){
        desenharMenu(sel1, sel2, sel3, x_imagem);
        al_flip_display();

        while(!al_event_queue_is_empty(fila_eventos)){
            ALLEGRO_EVENT evento;

            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
                switch(evento.keyboard.keycode){
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                }
            }
            else if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){

                if(evento.mouse.x > LARGURA * 0.4 && evento.mouse.x < LARGURA * 0.4 + al_get_bitmap_width(ico))
                {
                    if(evento.mouse.y > ALTURA * 0.15 && evento.mouse.y < ALTURA * 0.15 + al_get_bitmap_height(ico))
                    {
                        sel1 = true;
                    }
                    else
                    {
                        sel1 = false;
                    }
                    if(evento.mouse.y > ALTURA * 0.40 && evento.mouse.y < ALTURA * 0.40 + al_get_bitmap_height(ico))
                    {
                        sel2 = true;
                    }
                    else
                    {
                        sel2 = false;
                    }
                    if(evento.mouse.y > ALTURA * 0.65 && evento.mouse.y < ALTURA * 0.65 + al_get_bitmap_height(ico))
                    {
                        sel3 = true;
                    }
                    else
                    {
                        sel3 = false;
                    }
                }
                else
                {
                    sel1 = false;
                    sel2 = false;
                    sel3 = false;
                }

            }

            else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) ///manipular o mouse
            {
                if(evento.mouse.x > LARGURA * 0.4 && evento.mouse.x < LARGURA * 0.4 + al_get_bitmap_width(ico))
                {
                    if(evento.mouse.y > ALTURA * 0.15 && evento.mouse.y < ALTURA  * 0.15 + al_get_bitmap_height(ico))
                    {
                        al_unregister_event_source(fila_eventos, al_get_mouse_event_source());
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        al_set_audio_stream_playing(musica,false);
                        al_destroy_audio_stream(musica);
                        al_destroy_event_queue(fila_eventos);
                        al_destroy_bitmap(ico);

                        executarAviso();

                        musica = al_load_audio_stream("recursos/menu.ogg",4,1024);
                        ico = al_load_bitmap("recursos/menu1.png");
                        fila_eventos = al_create_event_queue();
                        al_register_event_source(fila_eventos, al_get_mouse_event_source());
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        al_set_audio_stream_playing(musica,true);
                    }
                    if(evento.mouse.y > ALTURA * 0.40 && evento.mouse.y < ALTURA  * 0.40 + al_get_bitmap_height(ico))
                    {
                        al_unregister_event_source(fila_eventos, al_get_mouse_event_source());
                        al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                        al_set_audio_stream_playing(musica,false);
                        al_destroy_audio_stream(musica);
                        al_destroy_event_queue(fila_eventos);
                        al_destroy_bitmap(ico);

                        executarComoJogar();

                        musica = al_load_audio_stream("recursos/menu.ogg",4,1024);
                        ico = al_load_bitmap("recursos/menu1.png");
                        fila_eventos = al_create_event_queue();
                        al_register_event_source(fila_eventos, al_get_mouse_event_source());
                        al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                        al_set_audio_stream_playing(musica,true);
                    }
                    if(evento.mouse.y > ALTURA * 0.65 && evento.mouse.y < ALTURA  * 0.65 + al_get_bitmap_height(ico))
                    {
                        sair = true;
                    }
                }
            }

        }

        if (x_imagem < LARGURA)
        {
            x_imagem += 8;
        }
        else
        {
            x_imagem = 0;
        }

    }
    al_unregister_event_source(fila_eventos, al_get_mouse_event_source());
    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());

    al_set_audio_stream_playing(musica,false);

    al_destroy_audio_stream(musica);
    al_destroy_event_queue(fila_eventos);
    al_destroy_bitmap(ico);

}
void desenharMenu(bool sel1, bool sel2, bool sel3, int x_imagem)
{
    ALLEGRO_BITMAP * fundo_menu = NULL;
    ALLEGRO_BITMAP *ico_1 = NULL;
    ALLEGRO_BITMAP *ico1_sel = NULL;
    ALLEGRO_BITMAP *ico_2 = NULL;
    ALLEGRO_BITMAP *ico2_sel = NULL;
    ALLEGRO_BITMAP *ico_3 = NULL;
    ALLEGRO_BITMAP *ico3_sel = NULL;

    ico_1 = al_load_bitmap("recursos/Jogar10.png");
    ico1_sel = al_load_bitmap("recursos/Jogar20_sel.png");
    ico_2 = al_load_bitmap("recursos/How20.png");
    ico2_sel = al_load_bitmap("recursos/How20_sel.png");
    ico_3 = al_load_bitmap("recursos/Sair30.png");
    ico3_sel = al_load_bitmap("recursos/Sair40_sel.png");
    fundo_menu = al_load_bitmap("recursos/road.jpeg");

    al_clear_to_color(al_map_rgb(255,255,255));
    al_draw_bitmap(fundo_menu,x_imagem,0,0);
    al_draw_bitmap(fundo_menu, x_imagem - LARGURA, 0,0);

    if(sel1)
    {
        al_draw_bitmap(ico1_sel, LARGURA * 0.4, ALTURA * 0.15, 0);

    }
    else
    {
        al_draw_bitmap(ico_1, LARGURA * 0.4, ALTURA * 0.15, 0);
    }
    if(sel2)
    {
        al_draw_bitmap(ico2_sel, LARGURA * 0.4, ALTURA * 0.40, 0);
    }
    else
    {
        al_draw_bitmap(ico_2, LARGURA * 0.4, ALTURA * 0.40, 0);
    }
    if(sel3)
    {
        al_draw_bitmap(ico3_sel, LARGURA * 0.4, ALTURA * 0.65, 0);
    }
    else
    {
        al_draw_bitmap(ico_3, LARGURA * 0.4, ALTURA * 0.65, 0);
    }

    al_destroy_bitmap(fundo_menu);
    al_destroy_bitmap(ico_1);
    al_destroy_bitmap(ico1_sel);
    al_destroy_bitmap(ico_2);
    al_destroy_bitmap(ico2_sel);
    al_destroy_bitmap(ico_3);
    al_destroy_bitmap(ico3_sel);
}

void cadastro()
{
    Tarq_cadastro arq_cadastro;
    Treg_cadastro reg_cadastro;

    desenharCadastro();
    arq_cadastro = fopen("Cadastro.dat", "ab");
    if(arq_cadastro == NULL)
    {
        printf("Falha na abertura do arquivo: Cadastro.dat");
    }
    else
    {
        printf("Nome do usuario: ");
        scanf("%s", reg_cadastro.nome);
        while(reg_cadastro.nome != 0)
        {
            printf("Cidade: ");
            scanf("%s", reg_cadastro.cidade);
            //printf("Idade: ");
            //scanf("%i", reg_cadastro.idade);

            fwrite(&reg_cadastro, sizeof(Treg_cadastro),1, arq_cadastro);

                system("cls");
                printf("Nome do usuario: ");
                scanf("%s", reg_cadastro.nome);
        }
       fclose(arq_cadastro);
    }
}

void desenharCadastro()
{
    ALLEGRO_BITMAP *botao = NULL, *botao_sel = NULL, *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    fonte = al_load_ttf_font("recursos/Ancherr.ttf",80,0);
    botao = al_load_bitmap("recursos/a (2).jpg");

    al_clear_to_color(al_map_rgb(0,0,0));

    al_draw_bitmap(botao,LARGURA *0.30,ALTURA*0.80,0);

    al_draw_text(fonte,al_map_rgb(255,0,0),693,300,ALLEGRO_ALIGN_CENTRE,"Nome: ");
    al_draw_text(fonte,al_map_rgb(255,0,0),693,400,ALLEGRO_ALIGN_CENTRE,"Cidade: ");
    al_draw_text(fonte,al_map_rgb(255,0,0),693,500,ALLEGRO_ALIGN_CENTRE,"Idade: ");

    al_destroy_font(fonte);

}
void executarComoJogar()
{
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    bool sair = false;

    fila_eventos = al_create_event_queue();

    al_register_event_source(fila_eventos, al_get_keyboard_event_source());

    while(!sair){

        desenharComoJogar();
        al_flip_display();

        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
    al_destroy_event_queue(fila_eventos);
}
void desenharComoJogar()
{
    ALLEGRO_BITMAP *botao = NULL, *botao_sel = NULL, *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    fonte = al_load_ttf_font("recursos/Ancherr.ttf",75,0);
    fundo_menu = al_load_bitmap("recursos/COMOJOGAR.jpg");

    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_bitmap(fundo_menu,0,0,0);

    al_destroy_font(fonte);
    al_destroy_bitmap(fundo_menu);
}

void executarAviso()
{
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;

    bool sair = false;

    fila_eventos = al_create_event_queue();




    al_register_event_source(fila_eventos, al_get_keyboard_event_source());

    while(!sair){

        desenharAviso();
        al_flip_display();

        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                case ALLEGRO_KEY_ENTER:
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    al_destroy_event_queue(fila_eventos);

                    al_stop_samples();
                    executarParte1(false);
                    sair = true;

                    fila_eventos = al_create_event_queue();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
    al_destroy_event_queue(fila_eventos);



}
void desenharAviso()
{

    ALLEGRO_FONT * fonte = NULL;
    ALLEGRO_BITMAP * imagem = NULL;

    fonte = al_load_ttf_font("recursos/Ancherr.ttf",90,0);
    imagem = al_load_bitmap("recursos/ab.jpg");

    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_bitmap(imagem,LARGURA *0.30,ALTURA*0.23,0);
    al_draw_bitmap(imagem,LARGURA *0.30,ALTURA*0.42,0);
    al_draw_bitmap(imagem,LARGURA *0.30,ALTURA*0.62,0);
    al_draw_text(fonte,al_map_rgb(255,0,0),180,150,ALLEGRO_ALIGN_CENTRE,"NOME: ");
    al_draw_text(fonte,al_map_rgb(255,0,0),180,300,ALLEGRO_ALIGN_CENTRE,"CIDADE:  ");
    al_draw_text(fonte,al_map_rgb(255,0,0),180,450,ALLEGRO_ALIGN_CENTRE,"IDADE:  ");

    al_destroy_font(fonte);

}

void executarParte1()
{
    bool sair = false;
    bool botao1 = false, botao2 = false;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_BITMAP *botao = NULL;

    fila_eventos = al_create_event_queue();
    botao = al_load_bitmap("recursos/preto11.png");

    al_register_event_source(fila_eventos, al_get_mouse_event_source());///faz com que a fila atenda a eventos gerados pelo mouse
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());

    while(!sair){

        desenharParte1(botao1, botao2);
        al_flip_display();

        while(!al_event_queue_is_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
                if(evento.mouse.x >= LARGURA*0.30 && evento.mouse.x <= LARGURA *0.30+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = true;///muda a imagem
                    botao2 = false;
                }
                else if(evento.mouse.x >= LARGURA*0.59 && evento.mouse.x <= LARGURA *0.59 + al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80&& evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = false;
                    botao2 = true;
                }
                else
                {
                    botao1 = false;
                    botao2 = false;
                }
            }
            else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                if(evento.mouse.x >= LARGURA*0.30 && evento.mouse.x <= LARGURA *0.30+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA*0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                     ///BOTAO DA PRIMEIRA ESCOLHA
                     executarParte2();
                }

                else
                {
                    if(evento.mouse.x >= LARGURA*0.59 && evento.mouse.x <= LARGURA *0.59+ al_get_bitmap_width(botao)&&
                            evento.mouse.y >= ALTURA*0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                    {
                        sair = true;
                    }
                }
            }
            else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
                switch(evento.keyboard.keycode){
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_mouse_event_source());
    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());

    al_destroy_bitmap(botao);
    al_destroy_event_queue(fila_eventos);

}
void desenharParte1(bool sel1, bool sel2)
{
    ALLEGRO_BITMAP *botao = NULL, *botao_sel = NULL, *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    botao = al_load_bitmap("recursos/preto11.png");
    botao_sel = al_load_bitmap("recursos/roxo11.png");
    fundo_menu = al_load_bitmap("recursos/AQUI.jpg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",75,0);

    al_clear_to_color(al_map_rgb(0,0,0));

    al_draw_bitmap(fundo_menu,0,0,0);
    //al_draw_text(fonte,al_map_rgb(255,255,0),699,70,ALLEGRO_ALIGN_CENTRE,"NESTE JOGO VOCE IRA INCORPORAR ETHAN,");
    //al_draw_text(fonte,al_map_rgb(255,255,0),699,150,ALLEGRO_ALIGN_CENTRE,"UM POLICIAL AFASTADO QUE PROCURA SOSSEGO. ");
    //al_draw_text(fonte,al_map_rgb(255,255,0),699,230,ALLEGRO_ALIGN_CENTRE,"CANSADO DE TANTA CORRERIA, ETHAN SE MUDA ");
    //al_draw_text(fonte,al_map_rgb (255,255,0),699,310,ALLEGRO_ALIGN_CENTRE,"PARA UMA CASA AFASTADA DA POPULACAO.");


    if(sel1){
        al_draw_bitmap(botao_sel,LARGURA *0.30,ALTURA*0.80,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.30,ALTURA*0.80,0);
    }
    if(sel2){
        al_draw_bitmap(botao_sel,LARGURA *0.59,ALTURA*0.80,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.59,ALTURA*0.80,0);
    }

    al_draw_text(fonte,al_map_rgb(255,255,255),250,609,ALLEGRO_ALIGN_CENTRE,"OK, ENTENDI.");
    al_draw_text(fonte,al_map_rgb(255,255,255),1080,590,ALLEGRO_ALIGN_CENTRE,"ESTOU INDECISO,");
    al_draw_text(fonte,al_map_rgb(255,255,255),1080,630,ALLEGRO_ALIGN_CENTRE,"QUERO DESISTIR!");


    al_destroy_bitmap(botao);
    al_destroy_bitmap(botao_sel);
    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);
}



void executarParte2()
{
    bool sair = false;
    bool botao1 = false, botao2 = false;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_BITMAP *botao = NULL;
    ALLEGRO_SAMPLE * Primeiro_som = NULL;

    fila_eventos = al_create_event_queue();
    botao = al_load_bitmap("recursos/preto11.png");
    Primeiro_som = al_load_sample("recursos/1.ogg");

    al_play_sample(Primeiro_som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);


    al_register_event_source(fila_eventos, al_get_mouse_event_source());///faz com que a fila atenda a eventos gerados pelo mouse
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());

    while(!sair){

        desenharParte2(botao1, botao2);
        al_flip_display();

        while(!al_event_queue_is_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
                if(evento.mouse.x >= LARGURA*0.33 && evento.mouse.x <= LARGURA *0.33+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = true;///muda a imagem
                    botao2 = false;
                }
                else if(evento.mouse.x >= LARGURA*0.56 && evento.mouse.x <= LARGURA *0.56 + al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80&& evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = false;
                    botao2 = true;
                }
                else
                {
                    botao1 = false;
                    botao2 = false;
                }
            }
            else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                if(evento.mouse.x >= LARGURA*0.32 && evento.mouse.x <= LARGURA *0.32+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA*0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                     ///BOTAO DEIXAR CARRO
                        al_stop_samples();
                        executarParte3();
                        sair = true;
                }

                else
                {
                    if(evento.mouse.x >= LARGURA*0.57 && evento.mouse.x <= LARGURA *0.57+ al_get_bitmap_width(botao)&&
                            evento.mouse.y >= ALTURA*0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                    {
                        /// OLHAR PORTA LUVAS
                        al_stop_samples();
                        executarParte3_1();
                        sair = true;
                    }
                }
            }
            else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
                switch(evento.keyboard.keycode){
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_mouse_event_source());
    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());

    al_destroy_bitmap(botao);
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(Primeiro_som);

}

void desenharParte2(bool sel1, bool sel2)
{
    ALLEGRO_BITMAP *botao = NULL, *botao_sel = NULL, *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    botao = al_load_bitmap("recursos/preto11.png");
    botao_sel = al_load_bitmap("recursos/roxo11.png");
    fundo_menu = al_load_bitmap("recursos/imgintroduçao.jpg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",75,0);

    al_clear_to_color(al_map_rgb(0,0,0));

    //al_draw_bitmap(fundo_menu,0,0,0);


    if(sel1){
        al_draw_bitmap(botao_sel,LARGURA *0.32,ALTURA*0.80,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.32,ALTURA*0.80,0);
    }
    if(sel2){
        al_draw_bitmap(botao_sel,LARGURA *0.57,ALTURA*0.80,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.57,ALTURA*0.80,0);
    }


    al_draw_text(fonte,al_map_rgb(255,255,255),250,615,ALLEGRO_ALIGN_CENTRE,"DEIXAR O CARRO");
    al_draw_text(fonte,al_map_rgb(255,255,255),1080,615,ALLEGRO_ALIGN_CENTRE,"OLHAR PORTA LUVAS");


    al_destroy_bitmap(botao);
    al_destroy_bitmap(botao_sel);
    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);
}


void executarParte3()
{
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_SAMPLE * Segundo_som = NULL;
    bool sair = false;

    fila_eventos = al_create_event_queue();

    Segundo_som = al_load_sample("recursos/2.ogg");
    al_play_sample(Segundo_som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    al_register_event_source(fila_eventos, al_get_keyboard_event_source());

    while(!sair){

        desenharParte3();
        al_flip_display();

        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                case ALLEGRO_KEY_ENTER:
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    al_destroy_event_queue(fila_eventos);

                    al_stop_samples();
                    executarParte4(false);
                    sair = true;

                    fila_eventos = al_create_event_queue();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(Segundo_som);

}

void desenharParte3()
{
    ALLEGRO_FONT * fonte = NULL;

    fonte = al_load_ttf_font("recursos/Ancherr.ttf",80,0);

    al_clear_to_color(al_map_rgb(0,0,0));

    al_draw_text(fonte,al_map_rgb(255,0,0),693,210,ALLEGRO_ALIGN_CENTRE,"APOS A ANIMACAO PRESSIONE ENTER PARA PROSSEGUIR");

    al_destroy_font(fonte);

}


void executarParte3_1()
{
    bool sair = false;
    bool botao1 = false, botao2 = false;
    bool pegouIsqueiro = false;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_BITMAP *botao = NULL;
    ALLEGRO_SAMPLE * Terceiro_som = NULL;

    fila_eventos = al_create_event_queue();
    botao = al_load_bitmap("recursos/preto11.png");
    Terceiro_som = al_load_sample("recursos/1ISQUEIRO.ogg");
    al_play_sample(Terceiro_som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    al_register_event_source(fila_eventos, al_get_mouse_event_source());///faz com que a fila atenda a eventos gerados pelo mouse
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());

    while(!sair){

        desenharParte3_1(botao1, botao2);
        al_flip_display();

        while(!al_event_queue_is_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
                if(evento.mouse.x >= LARGURA*0.33 && evento.mouse.x <= LARGURA *0.33+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = true;///muda a imagem
                    botao2 = false;
                }
                else if(evento.mouse.x >= LARGURA*0.57 && evento.mouse.x <= LARGURA *0.57 + al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80&& evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = false;
                    botao2 = true;
                }
                else
                {
                    botao1 = false;
                    botao2 = false;
                }
            }
            else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                if(evento.mouse.x >= LARGURA*0.31 && evento.mouse.x <= LARGURA *0.31+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA*0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                     ///BOTAO PEGAR ISQUEIRO
                     pegouIsqueiro = true;
                     al_stop_samples();
                     executarParte4(pegouIsqueiro);
                     sair = true;
                }

                else
                {
                    if(evento.mouse.x >= LARGURA*0.58 && evento.mouse.x <= LARGURA *0.58+ al_get_bitmap_width(botao)&&
                            evento.mouse.y >= ALTURA*0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                    {
                        ///BOTAO DEIXAR ISQUEIRO
                        al_stop_samples();
                         executarParte4(pegouIsqueiro);
                         sair = true;
                    }
                }
            }
            else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
                switch(evento.keyboard.keycode){
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_mouse_event_source());
    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());

    al_destroy_bitmap(botao);
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(Terceiro_som);

}

void desenharParte3_1(bool sel1, bool sel2)
{
    ALLEGRO_BITMAP *botao = NULL, *botao_sel = NULL, *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    botao = al_load_bitmap("recursos/preto11.png");
    botao_sel = al_load_bitmap("recursos/roxo11.png");
    fundo_menu = al_load_bitmap("recursos/portaluvas.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",75,0);

    al_clear_to_color(al_map_rgb(0,0,0));

    al_draw_bitmap(fundo_menu,0,0,0);



    if(sel1){
        al_draw_bitmap(botao_sel,LARGURA *0.31,ALTURA*0.80,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.31,ALTURA*0.80,0);
    }
    if(sel2){
        al_draw_bitmap(botao_sel,LARGURA *0.58,ALTURA*0.80,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.58,ALTURA*0.80,0);
    }

    al_draw_text(fonte,al_map_rgb(255,255,255),220,615,ALLEGRO_ALIGN_CENTRE,"PEGAR ISQUEIRO.");
    al_draw_text(fonte,al_map_rgb(255,255,255),1080,615,ALLEGRO_ALIGN_CENTRE,"DEIXAR ISQUEIRO");



    al_destroy_bitmap(botao);
    al_destroy_bitmap(botao_sel);
    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}

void executarParte4(bool pegouIsqueiro)
{
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_SAMPLE * Quarto_som = NULL;
    bool sair = false;

    Quarto_som = al_load_sample("recursos/3.ogg");
    al_play_sample(Quarto_som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    fila_eventos = al_create_event_queue();
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());



    while(!sair){

        desenharParte4();
        al_flip_display();

        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                case ALLEGRO_KEY_ENTER:
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    al_destroy_event_queue(fila_eventos);

                    al_stop_samples();
                    executarParte5(pegouIsqueiro);
                    sair = true;

                    fila_eventos = al_create_event_queue();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
    al_destroy_event_queue(fila_eventos);
     al_destroy_sample(Quarto_som);
}

void desenharParte4()
{
    ALLEGRO_FONT * fonte = NULL;

    fonte = al_load_ttf_font("recursos/Ancherr.ttf",80,0);

    al_clear_to_color(al_map_rgb(0,0,0));

    al_draw_text(fonte,al_map_rgb(255,0,0),693,210,ALLEGRO_ALIGN_CENTRE,"APOS A ANIMACAO PRESSIONE ENTER PARA PROSSEGUIR");

    al_destroy_font(fonte);

}



void executarParte5(bool pegouIsqueiro)
{
    bool sair = false;
    bool botao1 = false, botao2 = false;
    bool iniciarCont = false;
    int frame = 0;

    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_BITMAP *botao = NULL;
    ALLEGRO_SAMPLE * Quinto_som = NULL;

    fila_eventos = al_create_event_queue();
    botao = al_load_bitmap("recursos/preto11.png");
    Quinto_som = al_load_sample("recursos/5.ogg");
    al_play_sample(Quinto_som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    al_register_event_source(fila_eventos, al_get_mouse_event_source());///faz com que a fila atenda a eventos gerados pelo mouse
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());

    while(!sair){

        desenharParte5(botao1, botao2, frame);
        al_flip_display();

        if(iniciarCont){
            frame = frame + 10;
        }

        while(!al_event_queue_is_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
                if(evento.mouse.x >= LARGURA*0.36 && evento.mouse.x <= LARGURA *0.36+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = true;///muda a imagem
                    botao2 = false;
                }
                else if(evento.mouse.x >= LARGURA*0.56 && evento.mouse.x <= LARGURA *0.56 + al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80&& evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = false;
                    botao2 = true;
                }
                else
                {
                    botao1 = false;
                    botao2 = false;
                }
            }
            else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                if(evento.mouse.x >= LARGURA*0.35 && evento.mouse.x <= LARGURA *0.35+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA*0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    al_stop_samples();
                    iniciarCont = true;


                }

            }
            else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
                switch(evento.keyboard.keycode){
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                }
            }
        }

        if(frame > 300){
            if(pegouIsqueiro){

                executarParte6_isqueiro();
                sair = true;
            }
            else{
                executarParte6_N_isqueiro();
                sair = true;
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_mouse_event_source());
    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());

    al_destroy_bitmap(botao);
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(Quinto_som);

}

void desenharParte5(bool sel1, bool sel2, int frame)
{
    ALLEGRO_BITMAP *botao = NULL, *botao_sel = NULL, *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    botao = al_load_bitmap("recursos/preto11.png");
    botao_sel = al_load_bitmap("recursos/roxo11.png");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",75,0);

    al_clear_to_color(al_map_rgb(0,0,0));


    if(frame == 0){
        fundo_menu = al_load_bitmap("recursos/ConfusedStories1.jpeg");
        al_draw_bitmap(fundo_menu,0,0,0);
    }
    else if(frame > 0 && frame <= 30){
        fundo_menu = al_load_bitmap("recursos/ConfusedStories1.jpeg");
        al_draw_bitmap(fundo_menu,0,0,1);
    }
    else if(frame > 30 && frame <= 60){
        fundo_menu = al_load_bitmap("recursos/ConfusedStories1.jpeg");
        al_draw_bitmap(fundo_menu,0,0,2);
    }
    else if(frame > 90 && frame <= 120){
        fundo_menu = al_load_bitmap("recursos/ConfusedStories1.jpeg");
        al_draw_bitmap(fundo_menu,0,0,3);
    }
       if(frame == 0){
        fundo_menu = al_load_bitmap("recursos/ConfusedStories1.jpeg");
        al_draw_bitmap(fundo_menu,0,0,0);
    }
    else if(frame > 120 && frame <= 150){
        fundo_menu = al_load_bitmap("recursos/ConfusedStories1.jpeg");
        al_draw_bitmap(fundo_menu,0,0,1);
    }
    else if(frame > 150 && frame <= 180){
        fundo_menu = al_load_bitmap("recursos/ConfusedStories1.jpeg");
        al_draw_bitmap(fundo_menu,0,0,2);
    }
    else if(frame > 210 && frame <= 240){
        fundo_menu = al_load_bitmap("recursos/ConfusedStories1.jpeg");
        al_draw_bitmap(fundo_menu,0,0,3);
    }



    if(sel1){
        al_draw_bitmap(botao_sel,LARGURA *0.35,ALTURA*0.80,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.35,ALTURA*0.80,0);
    }

    al_draw_text(fonte,al_map_rgb(255,255,255),710,610,ALLEGRO_ALIGN_CENTRE,"ABRIR PORTA");



    al_destroy_bitmap(botao);
    al_destroy_bitmap(botao_sel);
    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}

void executarParte6_isqueiro()
{
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_SAMPLE * Sexto_som = NULL;
    bool sair = false;

    Sexto_som = al_load_sample("recursos/5.5COMISQ.ogg");
    al_play_sample(Sexto_som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    fila_eventos = al_create_event_queue();
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());



    while(!sair){

        desenharParte6_isqueiro();
        al_flip_display();

        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                case ALLEGRO_KEY_ENTER:
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    al_destroy_event_queue(fila_eventos);

                    al_stop_samples();
                    executarParte7();
                    sair = true;

                    fila_eventos = al_create_event_queue();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(Sexto_som);

}

void desenharParte6_isqueiro()
{
    ALLEGRO_BITMAP *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    fundo_menu = al_load_bitmap("recursos/ConfusedStories2.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",80,0);

    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_bitmap(fundo_menu,0,0,0);

    al_draw_text(fonte,al_map_rgb(255,255,0),693,210,ALLEGRO_ALIGN_CENTRE,"APOS A ANIMACAO PRESSIONE ENTER PARA PROSSEGUIR");

    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);
}


void executarParte6_N_isqueiro()
{
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_SAMPLE * Sexto_som = NULL;
    bool sair = false;

    Sexto_som = al_load_sample("recursos/4SEMISQUEIRO.ogg");
    al_play_sample(Sexto_som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    fila_eventos = al_create_event_queue();
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());



    while(!sair){

        desenharParte6_N_isqueiro();
        al_flip_display();

        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                case ALLEGRO_KEY_ENTER:
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    al_destroy_event_queue(fila_eventos);

                     al_stop_samples();
                     executarParte7();
                     sair= true;

                    fila_eventos = al_create_event_queue();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(Sexto_som);

}

void desenharParte6_N_isqueiro()
{
    ALLEGRO_BITMAP *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    fundo_menu = al_load_bitmap("recursos/ConfusedStories2.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",80,0);

    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_bitmap(fundo_menu,0,0,0);

    al_draw_text(fonte,al_map_rgb(255,255,0),693,210,ALLEGRO_ALIGN_CENTRE,"APOS A ANIMACAO PRESSIONE ENTER PARA PROSSEGUIR");

    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}


void executarParte7()
{
    bool sair = false;
    bool botao1 = false, botao2 = false;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_BITMAP *botao = NULL;
    ALLEGRO_SAMPLE * Oitavo_som = NULL;

    fila_eventos = al_create_event_queue();
    botao = al_load_bitmap("recursos/preto11.png");
    Oitavo_som = al_load_sample("recursos/6.ogg");
    al_play_sample(Oitavo_som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    al_register_event_source(fila_eventos, al_get_mouse_event_source());///faz com que a fila atenda a eventos gerados pelo mouse
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());

    while(!sair){

        desenharParte7(botao1, botao2);
        al_flip_display();

        while(!al_event_queue_is_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
                if(evento.mouse.x >= LARGURA*0.36 && evento.mouse.x <= LARGURA *0.36+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = true;///muda a imagem
                    botao2 = false;
                }
                else if(evento.mouse.x >= LARGURA*0.56 && evento.mouse.x <= LARGURA *0.56 + al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80&& evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = false;
                    botao2 = true;
                }
                else
                {
                    botao1 = false;
                    botao2 = false;
                }
            }
            else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                if(evento.mouse.x >= LARGURA*0.37 && evento.mouse.x <= LARGURA *0.37+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA*0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                     ///BOTAO LEVANTAR
                     al_stop_samples();
                    executarParte8();
                    sair = true;
                }


            }
            else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
                switch(evento.keyboard.keycode){
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_mouse_event_source());
    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());

    al_destroy_bitmap(botao);
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(Oitavo_som);

}

void desenharParte7(bool sel1, bool sel2)
{
    ALLEGRO_BITMAP *botao = NULL, *botao_sel = NULL, *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    botao = al_load_bitmap("recursos/preto11.png");
    botao_sel = al_load_bitmap("recursos/roxo11.png");
    fundo_menu = al_load_bitmap("recursos/ConfusedStories5.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",75,0);

    al_clear_to_color(al_map_rgb(0,0,0));

    al_draw_bitmap(fundo_menu,0,0,0);



    if(sel1){
        al_draw_bitmap(botao_sel,LARGURA *0.37,ALTURA*0.80,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.37,ALTURA*0.80,0);
    }



    al_draw_text(fonte,al_map_rgb(255,255,255),710,610,ALLEGRO_ALIGN_CENTRE,"LEVANTAR");



    al_destroy_bitmap(botao);
    al_destroy_bitmap(botao_sel);
    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}




void executarParte8()
{
    bool sair = false;
    bool botao1 = false, botao2 = false, botao3 = false;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_BITMAP *botao = NULL;
    ALLEGRO_SAMPLE * Nono_som = NULL;

    fila_eventos = al_create_event_queue();
    botao = al_load_bitmap("recursos/preto11.png");
    Nono_som = al_load_sample("recursos/7.ogg");
    al_play_sample(Nono_som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    al_register_event_source(fila_eventos, al_get_mouse_event_source());///faz com que a fila atenda a eventos gerados pelo mouse
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());

    while(!sair){

        desenharParte8(botao1, botao2, botao3);
        al_flip_display();

        while(!al_event_queue_is_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
                if(evento.mouse.x >= LARGURA*0.30 && evento.mouse.x <= LARGURA *0.30+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.70 && evento.mouse.y <= ALTURA*0.70+ al_get_bitmap_height(botao))
                {
                    botao1 = true;///muda a imagem
                    botao2 = false;
                    botao3 = false;
                }
                else if(evento.mouse.x >= LARGURA*0.64 && evento.mouse.x <= LARGURA *0.64 + al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.70&& evento.mouse.y <= ALTURA*0.70 + al_get_bitmap_height(botao))
                {
                    botao1 = false;
                    botao2 = true;
                    botao3 = false;
                }
                else if(evento.mouse.x >= LARGURA*0.40 && evento.mouse.x <= LARGURA *0.40 + al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.87&& evento.mouse.y <= ALTURA*0.87 + al_get_bitmap_height(botao))
                {
                    botao1 = false;
                    botao2 = false;
                    botao3 = true;
                }


                else
                {
                    botao1 = false;
                    botao2 = false;
                    botao3 = false;
                }
            }
            else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                if(evento.mouse.x >= LARGURA*0.32 && evento.mouse.x <= LARGURA *0.32+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA*0.70 && evento.mouse.y <= ALTURA*0.70 + al_get_bitmap_height(botao))
                {
                          ///BOTAO IR PARA ESQUERDA
                          al_stop_samples();
                          executarParte8E();
                          sair = true;
                }

                else
                {
                    if(evento.mouse.x >= LARGURA*0.64 && evento.mouse.x <= LARGURA *0.64+ al_get_bitmap_width(botao)&&
                            evento.mouse.y >= ALTURA*0.70 && evento.mouse.y <= ALTURA*0.70 + al_get_bitmap_height(botao))
                    {
                           ///BOTAO IR PARA DIREITA
                           al_stop_samples();
                           executarParte8D();
                           sair = true;
                    }
                    else{
                       if(evento.mouse.x >= LARGURA*0.40 && evento.mouse.x <= LARGURA *0.40+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA*0.87 && evento.mouse.y <= ALTURA*0.87 + al_get_bitmap_height(botao))
                        {
                           ///BOTAO TENTAR ESCALAR
                           al_stop_samples();
                           executarParte8T();
                           sair = true;

                        }
                    }

                }
            }
            else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
                switch(evento.keyboard.keycode){
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_mouse_event_source());
    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());

    al_destroy_bitmap(botao);
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(Nono_som);


}

 void desenharParte8(bool sel1, bool sel2, bool sel3)
{
    {
    ALLEGRO_BITMAP *botao = NULL, *botao_sel = NULL, *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    botao = al_load_bitmap("recursos/preto11.png");
    botao_sel = al_load_bitmap("recursos/roxo11.png");
    fundo_menu = al_load_bitmap("recursos/ConfusedStories3.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",75,0);

    al_clear_to_color(al_map_rgb(0,0,0));

    al_draw_bitmap(fundo_menu,0,0,0);



    if(sel1){
        al_draw_bitmap(botao_sel,LARGURA *0.32,ALTURA*0.70,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.32,ALTURA*0.70,0);
    }
    if(sel2){
        al_draw_bitmap(botao_sel,LARGURA *0.64,ALTURA*0.70,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.64,ALTURA*0.70,0);
    }
    if(sel3){
        al_draw_bitmap(botao_sel,LARGURA *0.40,ALTURA*0.87,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.40,ALTURA*0.87,0);
    }

    al_draw_text(fonte,al_map_rgb(255,255,255),1130,540,ALLEGRO_ALIGN_CENTRE,"IR PELA DIREITA");
    al_draw_text(fonte,al_map_rgb(255,255,255),213,540,ALLEGRO_ALIGN_CENTRE,"IR PELA ESQUERDA");
    al_draw_text(fonte,al_map_rgb(255,255,255),820,670,ALLEGRO_ALIGN_CENTRE,"TENTAR ESCALAR");





    al_destroy_bitmap(botao);
    al_destroy_bitmap(botao_sel);
    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}

}

void executarParte8D()
{
    bool sair = false;
    bool botao1 = false, botao2 = false;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_BITMAP *botao = NULL;
    ALLEGRO_SAMPLE * Decimo_som = NULL;

    fila_eventos = al_create_event_queue();
    botao = al_load_bitmap("recursos/preto11.png");
    Decimo_som = al_load_sample("recursos/8DIR.ogg");
    al_play_sample(Decimo_som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    al_register_event_source(fila_eventos, al_get_mouse_event_source());///faz com que a fila atenda a eventos gerados pelo mouse
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());

    while(!sair){

        desenharParte8D(botao1, botao2);
        al_flip_display();

        while(!al_event_queue_is_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
                if(evento.mouse.x >= LARGURA*0.31 && evento.mouse.x <= LARGURA *0.31+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = true;///muda a imagem
                    botao2 = false;
                }
                else if(evento.mouse.x >= LARGURA*0.60 && evento.mouse.x <= LARGURA *0.60 + al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80&& evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = false;
                    botao2 = true;
                }
                else
                {
                    botao1 = false;
                    botao2 = false;
                }
            }
            else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                if(evento.mouse.x >= LARGURA*0.31 && evento.mouse.x <= LARGURA *0.31+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA*0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                     ///BOTAO IR COM CUIDADO
                     al_stop_samples();
                     executarParte9D();
                     sair = true;
                }

                else
                {
                    if(evento.mouse.x >= LARGURA*0.60 && evento.mouse.x <= LARGURA *0.60+ al_get_bitmap_width(botao)&&
                            evento.mouse.y >= ALTURA*0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                    {
                        ///BOTAO CORRER ATE O DESCONHECIDO
                        al_stop_samples();
                        executarParte9D();
                        sair = true;
                    }
                }
            }
            else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
                switch(evento.keyboard.keycode){
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_mouse_event_source());
    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());

    al_destroy_bitmap(botao);
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(Decimo_som);

}

void desenharParte8D(bool sel1, bool sel2)
{
    ALLEGRO_BITMAP *botao = NULL, *botao_sel = NULL, *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    botao = al_load_bitmap("recursos/preto11.png");
    botao_sel = al_load_bitmap("recursos/roxo11.png");
    fundo_menu = al_load_bitmap("recursos/ConfusedStories4.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",75,0);

    al_clear_to_color(al_map_rgb(0,0,0));

    al_draw_bitmap(fundo_menu,0,0,0);



    if(sel1){
        al_draw_bitmap(botao_sel,LARGURA *0.31,ALTURA*0.80,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.31,ALTURA*0.80,0);
    }
    if(sel2){
        al_draw_bitmap(botao_sel,LARGURA *0.60,ALTURA*0.80,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.60,ALTURA*0.80,0);
    }

    al_draw_text(fonte,al_map_rgb(255,255,255),220,615,ALLEGRO_ALIGN_CENTRE,"IR COM CUIDADO.");
    al_draw_text(fonte,al_map_rgb(255,255,255),1080,590,ALLEGRO_ALIGN_CENTRE,"CORRER ATE O");
    al_draw_text(fonte,al_map_rgb(255,255,255),1080,640,ALLEGRO_ALIGN_CENTRE,"DESCONHECIDO");



    al_destroy_bitmap(botao);
    al_destroy_bitmap(botao_sel);
    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}


void executarParte8E()
{
    bool sair = false;
    bool botao1 = false, botao2 = false;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_BITMAP *botao = NULL;
    ALLEGRO_SAMPLE * Decimo1_som = NULL;

    fila_eventos = al_create_event_queue();
    botao = al_load_bitmap("recursos/preto11.png");
    Decimo1_som = al_load_sample("recursos/8ESQ.ogg");
    al_play_sample(Decimo1_som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    al_register_event_source(fila_eventos, al_get_mouse_event_source());///faz com que a fila atenda a eventos gerados pelo mouse
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());

    while(!sair){

        desenharParte8E(botao1, botao2);
        al_flip_display();

        while(!al_event_queue_is_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
                if(evento.mouse.x >= LARGURA*0.39 && evento.mouse.x <= LARGURA *0.39+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.84 && evento.mouse.y <= ALTURA*0.84 + al_get_bitmap_height(botao))
                {
                    botao1 = true;///muda a imagem
                    botao2 = false;
                }
                else if(evento.mouse.x >= LARGURA*0.56 && evento.mouse.x <= LARGURA *0.56 + al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.84&& evento.mouse.y <= ALTURA*0.84 + al_get_bitmap_height(botao))
                {
                    botao1 = false;
                    botao2 = true;
                }
                else
                {
                    botao1 = false;
                    botao2 = false;
                }
            }
            else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                if(evento.mouse.x >= LARGURA*0.39 && evento.mouse.x <= LARGURA *0.39+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA*0.84 && evento.mouse.y <= ALTURA*0.84 + al_get_bitmap_height(botao))
                {
                     ///BOTAO AJUDAR DESCONHECIDO
                     al_stop_samples();
                     executarParte9D();
                     sair = true;
                }

                else
                {
                    if(evento.mouse.x >= LARGURA*0.56 && evento.mouse.x <= LARGURA *0.56+ al_get_bitmap_width(botao)&&
                            evento.mouse.y >= ALTURA*0.84 && evento.mouse.y <= ALTURA*0.84 + al_get_bitmap_height(botao))
                    {
                        ///BOTAO ATRAVESSAR BURRACO
                        al_stop_samples();
                        executarParte9_1E();
                        sair = true;

                    }
                }
            }
            else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
                switch(evento.keyboard.keycode){
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_mouse_event_source());
    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());

    al_destroy_bitmap(botao);
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(Decimo1_som);

}
void desenharParte8E(bool sel1, bool sel2)
{
    ALLEGRO_BITMAP *botao = NULL, *botao_sel = NULL, *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    botao = al_load_bitmap("recursos/preto11.png");
    botao_sel = al_load_bitmap("recursos/roxo11.png");
    fundo_menu = al_load_bitmap("recursos/ConfusedStories4.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",75,0);

    al_clear_to_color(al_map_rgb(0,0,0));

    al_draw_bitmap(fundo_menu,0,0,0);



    if(sel1){
        al_draw_bitmap(botao_sel,LARGURA *0.39,ALTURA*0.84,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.39,ALTURA*0.84,0);
    }
    if(sel2){
        al_draw_bitmap(botao_sel,LARGURA *0.56,ALTURA*0.84,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.56,ALTURA*0.84,0);
    }

    al_draw_text(fonte,al_map_rgb(255,255,255),260,644,ALLEGRO_ALIGN_CENTRE,"AJUDAR DESCONHECIDO");
    al_draw_text(fonte,al_map_rgb(255,255,255),1080,644,ALLEGRO_ALIGN_CENTRE,"ATRAVESSAR BURACO.");




    al_destroy_bitmap(botao);
    al_destroy_bitmap(botao_sel);
    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}



void executarParte8T()
{
    bool sair = false;
    bool botao1 = false, botao2 = false;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_BITMAP *botao = NULL;
    ALLEGRO_SAMPLE * Decimo2_som = NULL;

    fila_eventos = al_create_event_queue();
    botao = al_load_bitmap("recursos/preto11.png");
    Decimo2_som = al_load_sample("recursos/8ESCA.ogg");
    al_play_sample(Decimo2_som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    al_register_event_source(fila_eventos, al_get_mouse_event_source());///faz com que a fila atenda a eventos gerados pelo mouse
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());

    while(!sair){

        desenharParte8T(botao1, botao2);
        al_flip_display();

        while(!al_event_queue_is_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
                if(evento.mouse.x >= LARGURA*0.33 && evento.mouse.x <= LARGURA *0.33+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = true;///muda a imagem
                    botao2 = false;
                }
                else if(evento.mouse.x >= LARGURA*0.60&& evento.mouse.x <= LARGURA *0.60 + al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80&& evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = false;
                    botao2 = true;
                }
                else
                {
                    botao1 = false;
                    botao2 = false;
                }
            }
            else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                if(evento.mouse.x >= LARGURA*0.33 && evento.mouse.x <= LARGURA *0.33+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA*0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                     ///BOTAO AJUDAR DESCONHECIDO
                     al_stop_samples();
                     executarParte8E();
                     sair = true;
                }

                else
                {
                    if(evento.mouse.x >= LARGURA*0.060&& evento.mouse.x <= LARGURA *0.60+ al_get_bitmap_width(botao)&&
                            evento.mouse.y >= ALTURA*0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                    {
                        ///BOTAO ATRAVESSAR BURRACO
                        al_stop_samples();
                        executarParte8D();
                        sair = true;
                    }
                }
            }
            else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
                switch(evento.keyboard.keycode){
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_mouse_event_source());
    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());

    al_destroy_bitmap(botao);
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(Decimo2_som);

}

void desenharParte8T(bool sel1, bool sel2)
{
    ALLEGRO_BITMAP *botao = NULL, *botao_sel = NULL, *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    botao = al_load_bitmap("recursos/preto11.png");
    botao_sel = al_load_bitmap("recursos/roxo11.png");
    fundo_menu = al_load_bitmap("recursos/portaluvas.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",75,0);

    al_clear_to_color(al_map_rgb(0,0,0));

    //al_draw_bitmap(fundo_menu,0,0,0);



    if(sel1){
        al_draw_bitmap(botao_sel,LARGURA *0.33,ALTURA*0.80,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.33,ALTURA*0.80,0);
    }
    if(sel2){
        al_draw_bitmap(botao_sel,LARGURA *0.60,ALTURA*0.80,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.60,ALTURA*0.80,0);
    }

    al_draw_text(fonte,al_map_rgb(255,255,255),220,615,ALLEGRO_ALIGN_CENTRE,"IR PELA ESQUERDA");
    al_draw_text(fonte,al_map_rgb(255,255,255),1080,615,ALLEGRO_ALIGN_CENTRE,"IR PELA DIREITA");




    al_destroy_bitmap(botao);
    al_destroy_bitmap(botao_sel);
    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}


void executarParte9D()
{
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_SAMPLE * Decimo3_som = NULL;
    bool sair = false;

    Decimo3_som = al_load_sample("recursos/9.ogg");
    al_play_sample(Decimo3_som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    fila_eventos = al_create_event_queue();
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());



    while(!sair){

        desenharParte9D();
        al_flip_display();

        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                case ALLEGRO_KEY_ENTER:
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    al_destroy_event_queue(fila_eventos);

                    al_stop_samples();
                     executarParte10D();
                     sair = true;

                    fila_eventos = al_create_event_queue();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(Decimo3_som);

}
desenharParte9D()
{
    ALLEGRO_BITMAP *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    fundo_menu = al_load_bitmap("recursos/ConfusedStories6.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",80,0);

    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_bitmap(fundo_menu,0,0,0);

    al_draw_text(fonte,al_map_rgb(255,0,0),693,210,ALLEGRO_ALIGN_CENTRE,"APOS A ANIMACAO PRESSIONE ENTER PARA PROSSEGUIR");

    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}


void executarParte9_1D()
{
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_SAMPLE * Decimo4_som = NULL;
    bool sair = false;

    Decimo4_som = al_load_sample("recursos/1.ogg");
    al_play_sample(Decimo4_som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    fila_eventos = al_create_event_queue();
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());



    while(!sair){

        desenharParte9_1D();
        al_flip_display();

        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                case ALLEGRO_KEY_ENTER:
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    al_destroy_event_queue(fila_eventos);

                     al_stop_samples();
                     executarParte10D();
                     sair = true;

                    fila_eventos = al_create_event_queue();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(Decimo4_som);

}

void desenharParte9_1D()
{
    ALLEGRO_BITMAP *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    fundo_menu = al_load_bitmap("recursos/ConfusedStories2.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",80,0);

    al_clear_to_color(al_map_rgb(0,0,0));
    //al_draw_bitmap(fundo_menu,0,0,0);

    al_draw_text(fonte,al_map_rgb(255,0,0),693,210,ALLEGRO_ALIGN_CENTRE,"APOS A ANIMACAO PRESSIONE ENTER PARA PROSSEGUIR");

    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}



void executarParte9E()
{
    bool sair = false;
    bool botao1 = false, botao2 = false;

    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_BITMAP *botao = NULL;
    ALLEGRO_SAMPLE * Decimo5_som = NULL;

    fila_eventos = al_create_event_queue();
    botao = al_load_bitmap("recursos/preto11.png");
    Decimo5_som = al_load_sample("recursos/9.ogg");
    al_play_sample(Decimo5_som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    al_register_event_source(fila_eventos, al_get_mouse_event_source());///faz com que a fila atenda a eventos gerados pelo mouse
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());

    while(!sair){

        desenharParte9E(botao1, botao2);
        al_flip_display();

        while(!al_event_queue_is_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
                if(evento.mouse.x >= LARGURA*0.35 && evento.mouse.x <= LARGURA *0.35+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = true;///muda a imagem
                    botao2 = false;
                }
                else if(evento.mouse.x >= LARGURA*0.56 && evento.mouse.x <= LARGURA *0.56 + al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80&& evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = false;
                    botao2 = true;
                }
                else
                {
                    botao1 = false;
                    botao2 = false;
                }
            }
            else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                if(evento.mouse.x >= LARGURA*0.35 && evento.mouse.x <= LARGURA *0.35+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA*0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                        al_stop_samples();
                        executarParte11();
                        sair = true;

                }

            }
            else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
                switch(evento.keyboard.keycode){
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_mouse_event_source());
    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());

    al_destroy_bitmap(botao);
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(Decimo5_som);

}

void desenharParte9E(bool sel1, bool sel2)
{
    ALLEGRO_BITMAP *botao = NULL, *botao_sel = NULL, *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    botao = al_load_bitmap("recursos/preto11.png");
    botao_sel = al_load_bitmap("recursos/roxo11.png");
    fundo_menu = al_load_bitmap("recursos/ConfusedStories1.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",75,0);

    al_clear_to_color(al_map_rgb(0,0,0));

    //al_draw_bitmap(fundo_menu,0,0,0);



    if(sel1){
        al_draw_bitmap(botao_sel,LARGURA *0.40,ALTURA*0.80,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.40,ALTURA*0.80,0);
    }

    al_draw_text(fonte,al_map_rgb(255,255,255),710,610,ALLEGRO_ALIGN_CENTRE,"SOLTAR DESCHONECIDO");



    al_destroy_bitmap(botao);
    al_destroy_bitmap(botao_sel);
    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);
}


void executarParte9_1E()
{
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_SAMPLE * Decimo6_som = NULL;
    bool sair = false;

    Decimo6_som = al_load_sample("recursos/9NAOAJUDOU.ogg");
    al_play_sample(Decimo6_som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    fila_eventos = al_create_event_queue();
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());



    while(!sair){

        desenharParte9_1E();
        al_flip_display();

        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                case ALLEGRO_KEY_ENTER:
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    al_destroy_event_queue(fila_eventos);

                     al_stop_samples();
                     executarParte11();
                     sair = true;

                    fila_eventos = al_create_event_queue();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(Decimo6_som);


}

void desenharParte9_1E()
{

    ALLEGRO_BITMAP *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    fundo_menu = al_load_bitmap("recursos/ConfusedStories2.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",80,0);

    al_clear_to_color(al_map_rgb(0,0,0));
    //al_draw_bitmap(fundo_menu,0,0,0);

    al_draw_text(fonte,al_map_rgb(255,0,0),693,210,ALLEGRO_ALIGN_CENTRE,"APOS A ANIMACAO PRESSIONE ENTER PARA PROSSEGUIR");

    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}


void executarParte10D()
{
    bool sair = false;
    bool botao1 = false, botao2 = false;

    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_BITMAP *botao = NULL;
    ALLEGRO_SAMPLE * Decimo7_som = NULL;

    fila_eventos = al_create_event_queue();
    botao = al_load_bitmap("recursos/preto11.png");
    Decimo7_som = al_load_sample("recursos/somCaverna.ogg");
    al_play_sample(Decimo7_som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    al_register_event_source(fila_eventos, al_get_mouse_event_source());///faz com que a fila atenda a eventos gerados pelo mouse
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());

    while(!sair){

        desenharParte10D(botao1, botao2);
        al_flip_display();

        while(!al_event_queue_is_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
                if(evento.mouse.x >= LARGURA*0.34 && evento.mouse.x <= LARGURA *0.34+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = true;///muda a imagem
                    botao2 = false;
                }
                else if(evento.mouse.x >= LARGURA*0.56 && evento.mouse.x <= LARGURA *0.56 + al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80&& evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = false;
                    botao2 = true;
                }
                else
                {
                    botao1 = false;
                    botao2 = false;
                }
            }
            else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                if(evento.mouse.x >= LARGURA*0.34 && evento.mouse.x <= LARGURA *0.34+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA*0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                        al_stop_samples();
                        executarParte10_1();
                        sair = true;

                }

            }
            else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
                switch(evento.keyboard.keycode){
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_mouse_event_source());
    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());

    al_destroy_bitmap(botao);
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(Decimo7_som);

}

void desenharParte10D(bool sel1, bool sel2)
{
    ALLEGRO_BITMAP *botao = NULL, *botao_sel = NULL, *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    botao = al_load_bitmap("recursos/preto11.png");
    botao_sel = al_load_bitmap("recursos/roxo11.png");
    fundo_menu = al_load_bitmap("recursos/ConfusedStories1.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",75,0);

    al_clear_to_color(al_map_rgb(0,0,0));

    //al_draw_bitmap(fundo_menu,0,0,0);



    if(sel1){
        al_draw_bitmap(botao_sel,LARGURA *0.34,ALTURA*0.80,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.34,ALTURA*0.80,0);
    }

    al_draw_text(fonte,al_map_rgb(255,255,255),803,610,ALLEGRO_ALIGN_CENTRE,"SOLTAR DESCONHECIDO");



    al_destroy_bitmap(botao);
    al_destroy_bitmap(botao_sel);
    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}


void executarParte10_1()
{
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_SAMPLE * Decimo4_som = NULL;
    bool sair = false;

    Decimo4_som = al_load_sample("recursos/10.ogg");
    al_play_sample(Decimo4_som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    fila_eventos = al_create_event_queue();
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());



    while(!sair){

        desenharParte9_1D();
        al_flip_display();

        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                case ALLEGRO_KEY_ENTER:
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    al_destroy_event_queue(fila_eventos);

                     al_stop_samples();
                     executarParte11();
                     sair = true;

                    fila_eventos = al_create_event_queue();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(Decimo4_som);

}

void desenharParte10_1()
{
    ALLEGRO_BITMAP *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    fundo_menu = al_load_bitmap("recursos/ConfusedStories2.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",80,0);

    al_clear_to_color(al_map_rgb(0,0,0));
    //al_draw_bitmap(fundo_menu,0,0,0);

    al_draw_text(fonte,al_map_rgb(255,0,0),693,210,ALLEGRO_ALIGN_CENTRE,"APOS A ANIMACAO PRESSIONE ENTER PARA PROSSEGUIR");

    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}


void executarParte11()
{
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_SAMPLE * Decimo8_som = NULL;
    bool sair = false;

    Decimo8_som = al_load_sample("recursos/11AJUDOU.ogg");
    al_play_sample(Decimo8_som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    fila_eventos = al_create_event_queue();
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());



    while(!sair){

        desenharParte11();
        al_flip_display();

        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                case ALLEGRO_KEY_ENTER:
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    al_destroy_event_queue(fila_eventos);

                     al_stop_samples();
                     executarParte12();
                     sair = true;

                    fila_eventos = al_create_event_queue();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(Decimo8_som);


}


void desenharParte11()
{
    ALLEGRO_BITMAP *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    fundo_menu = al_load_bitmap("recursos/ConfusedStories2.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",80,0);

    al_clear_to_color(al_map_rgb(0,0,0));
    //al_draw_bitmap(fundo_menu,0,0,0);

    al_draw_text(fonte,al_map_rgb(255,0,0),693,210,ALLEGRO_ALIGN_CENTRE,"APOS A ANIMACAO PRESSIONE ENTER PARA PROSSEGUIR");

    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}

void executarParte11_1()
{
        ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_SAMPLE * Decimo8_som = NULL;
    bool sair = false;

    Decimo8_som = al_load_sample("recursos/11NAOAJUDOU.ogg");
    al_play_sample(Decimo8_som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    fila_eventos = al_create_event_queue();
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());



    while(!sair){

        desenharParte11();
        al_flip_display();

        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                case ALLEGRO_KEY_ENTER:
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    al_destroy_event_queue(fila_eventos);

                     al_stop_samples();
                     executarParte12();
                     sair = true;

                    fila_eventos = al_create_event_queue();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(Decimo8_som);

}

void desenharParte11_1()
{
    ALLEGRO_BITMAP *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    fundo_menu = al_load_bitmap("recursos/ConfusedStories2.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",80,0);

    al_clear_to_color(al_map_rgb(0,0,0));
    //al_draw_bitmap(fundo_menu,0,0,0);

    al_draw_text(fonte,al_map_rgb(255,0,0),693,210,ALLEGRO_ALIGN_CENTRE,"APOS A ANIMACAO PRESSIONE ENTER PARA PROSSEGUIR");

    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}


void executarParte12()
{
    bool sair = false;
    bool botao1 = false, botao2 = false;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_BITMAP *botao = NULL;
    ALLEGRO_SAMPLE * Decimo9_som = NULL;

    fila_eventos = al_create_event_queue();
    botao = al_load_bitmap("recursos/preto11.png");
    Decimo9_som = al_load_sample("recursos/12.ogg");
    al_play_sample(Decimo9_som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    al_register_event_source(fila_eventos, al_get_mouse_event_source());///faz com que a fila atenda a eventos gerados pelo mouse
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());

    while(!sair){

        desenharParte12(botao1, botao2);
        al_flip_display();

        while(!al_event_queue_is_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
                if(evento.mouse.x >= LARGURA*0.29 && evento.mouse.x <= LARGURA *0.29+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = true;///muda a imagem
                    botao2 = false;
                }
                else if(evento.mouse.x >= LARGURA*0.59 && evento.mouse.x <= LARGURA *0.59 + al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80&& evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = false;
                    botao2 = true;
                }
                else
                {
                    botao1 = false;
                    botao2 = false;
                }
            }
            else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                if(evento.mouse.x >= LARGURA*0.29&& evento.mouse.x <= LARGURA *0.29+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA*0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                     ///BOTAO SEGUIR ELLIE.
                     al_stop_samples();
                     executarParte13();
                     sair = true;
                }

                else
                {
                    if(evento.mouse.x >= LARGURA*0.59 && evento.mouse.x <= LARGURA *0.59+ al_get_bitmap_width(botao)&&
                            evento.mouse.y >= ALTURA*0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                    {
                        ///BOTAO SEGUIR BARULHO
                        al_stop_samples();
                        executarParte13();
                        sair = true;
                    }
                }
            }
            else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
                switch(evento.keyboard.keycode){
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_mouse_event_source());
    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());

    al_destroy_bitmap(botao);
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(Decimo9_som);

}

void desenharParte12(bool sel1, bool sel2)
{
    ALLEGRO_BITMAP *botao = NULL, *botao_sel = NULL, *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    botao = al_load_bitmap("recursos/preto11.png");
    botao_sel = al_load_bitmap("recursos/roxo11.png");
    fundo_menu = al_load_bitmap("recursos/buscar.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",75,0);

    al_clear_to_color(al_map_rgb(0,0,0));

    al_draw_bitmap(fundo_menu,0,0,0);



    if(sel1){
        al_draw_bitmap(botao_sel,LARGURA *0.29,ALTURA*0.80,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.29,ALTURA*0.80,0);
    }
    if(sel2){
        al_draw_bitmap(botao_sel,LARGURA *0.59,ALTURA*0.80,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.59,ALTURA*0.80,0);
    }

    al_draw_text(fonte,al_map_rgb(255,255,255),220,616,ALLEGRO_ALIGN_CENTRE,"SEGUIR ELLIE.");
    al_draw_text(fonte,al_map_rgb(255,255,255),1080,615,ALLEGRO_ALIGN_CENTRE,"SEGUIR BARULHO.");



    al_destroy_bitmap(botao);
    al_destroy_bitmap(botao_sel);
    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}


void executarParte13()
{
        ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_SAMPLE * Decimo8_som = NULL;
    bool sair = false;

    Decimo8_som = al_load_sample("recursos/13.ogg");
    al_play_sample(Decimo8_som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    fila_eventos = al_create_event_queue();
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());



    while(!sair){

        desenharParte11();
        al_flip_display();

        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                case ALLEGRO_KEY_ENTER:
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    al_destroy_event_queue(fila_eventos);

                     al_stop_samples();
                     executarParte14();
                     sair = true;

                    fila_eventos = al_create_event_queue();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(Decimo8_som);


}

void desenharParte13(bool sel1, bool sel2)
{
    ALLEGRO_BITMAP *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    fundo_menu = al_load_bitmap("recursos/ConfusedStories2.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",80,0);

    al_clear_to_color(al_map_rgb(0,0,0));
    //al_draw_bitmap(fundo_menu,0,0,0);

    al_draw_text(fonte,al_map_rgb(255,0,0),693,210,ALLEGRO_ALIGN_CENTRE,"APOS A ANIMACAO PRESSIONE ENTER PARA PROSSEGUIR");

    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}


void executarParte14()
{
    bool sair = false;
    bool botao1 = false, botao2 = false;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_BITMAP *botao = NULL;
    ALLEGRO_SAMPLE * Decimo21_som = NULL;

    fila_eventos = al_create_event_queue();
    botao = al_load_bitmap("recursos/preto11.png");
    Decimo21_som = al_load_sample("recursos/14.ogg");
    al_play_sample(Decimo21_som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    al_register_event_source(fila_eventos, al_get_mouse_event_source());///faz com que a fila atenda a eventos gerados pelo mouse
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());

    while(!sair){

        desenharParte14(botao1, botao2);
        al_flip_display();

        while(!al_event_queue_is_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
                if(evento.mouse.x >= LARGURA*0.30 && evento.mouse.x <= LARGURA *0.30+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = true;///muda a imagem
                    botao2 = false;
                }
                else if(evento.mouse.x >= LARGURA*0.58 && evento.mouse.x <= LARGURA *0.58 + al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80&& evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = false;
                    botao2 = true;
                }
                else
                {
                    botao1 = false;
                    botao2 = false;
                }
            }
            else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                if(evento.mouse.x >= LARGURA*0.30 && evento.mouse.x <= LARGURA *0.30+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA*0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                     ///BOTAO ABRIR A PORTA.
                     al_stop_samples();
                    executarParte14_abrirporta();
                    sair = true;
                }

                else
                {
                    if(evento.mouse.x >= LARGURA*0.58 && evento.mouse.x <= LARGURA *0.58+ al_get_bitmap_width(botao)&&
                            evento.mouse.y >= ALTURA*0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                    {
                        ///BOTAO SEGUIR EM FRENTE
                        al_stop_samples();
                        executarParte14_seguirfrente();
                        sair = true;
                    }
                }
            }
            else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
                switch(evento.keyboard.keycode){
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_mouse_event_source());
    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());

    al_destroy_bitmap(botao);
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(Decimo21_som);

}

void desenharParte14(bool sel1, bool sel2)
{
    ALLEGRO_BITMAP *botao = NULL, *botao_sel = NULL, *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    botao = al_load_bitmap("recursos/preto11.png");
    botao_sel = al_load_bitmap("recursos/roxo11.png");
    fundo_menu = al_load_bitmap("recursos/portaluvas.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",75,0);

    al_clear_to_color(al_map_rgb(0,0,0));

    //al_draw_bitmap(fundo_menu,0,0,0);



    if(sel1){
        al_draw_bitmap(botao_sel,LARGURA *0.30,ALTURA*0.80,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.30,ALTURA*0.80,0);
    }
    if(sel2){
        al_draw_bitmap(botao_sel,LARGURA *0.58,ALTURA*0.80,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.58,ALTURA*0.80,0);
    }

    al_draw_text(fonte,al_map_rgb(255,255,255),220,615,ALLEGRO_ALIGN_CENTRE,"ABRIR A PORTA");
    al_draw_text(fonte,al_map_rgb(255,255,255),1080,615,ALLEGRO_ALIGN_CENTRE,"SEGUIR EM FRENTE");



    al_destroy_bitmap(botao);
    al_destroy_bitmap(botao_sel);
    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}


void executarParte14_abrirporta()
{
    bool sair = false;
    bool botao1 = false, botao2 = false;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_BITMAP *botao = NULL;
    ALLEGRO_SAMPLE * som = NULL;

    fila_eventos = al_create_event_queue();
    botao = al_load_bitmap("recursos/preto11.png");
    som = al_load_sample("recursos/15ENTROU.ogg");
    al_play_sample(som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    al_register_event_source(fila_eventos, al_get_mouse_event_source());///faz com que a fila atenda a eventos gerados pelo mouse
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());

    while(!sair){

        desenharParte14_abrirporta(botao1, botao2);
        al_flip_display();

        while(!al_event_queue_is_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
                if(evento.mouse.x >= LARGURA*0.37 && evento.mouse.x <= LARGURA *0.37+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = true;///muda a imagem
                    botao2 = false;
                }
                else if(evento.mouse.x >= LARGURA*0.58 && evento.mouse.x <= LARGURA *0.58+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80&& evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = false;
                    botao2 = true;
                }
                else
                {
                    botao1 = false;
                    botao2 = false;
                }
            }
            else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                if(evento.mouse.x >= LARGURA*0.37 && evento.mouse.x <= LARGURA *0.37+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA*0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                     ///BOTAO VOLTAR PARA AJUDAR.
                     al_stop_samples();
                    executarParte15();
                    sair = true;
                }

                else
                {
                    if(evento.mouse.x >= LARGURA*0.58 && evento.mouse.x <= LARGURA *0.58+ al_get_bitmap_width(botao)&&
                            evento.mouse.y >= ALTURA*0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                    {
                        ///BOTAO SEGUIR EM FRENTE
                        al_stop_samples();
                        executarParte15_1();
                        sair = true;
                    }
                }
            }
            else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
                switch(evento.keyboard.keycode){
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_mouse_event_source());
    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());

    al_destroy_bitmap(botao);
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(som);

}

void desenharParte14_abrirporta(bool sel1, bool sel2)
{
    ALLEGRO_BITMAP *botao = NULL, *botao_sel = NULL, *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    botao = al_load_bitmap("recursos/preto11.png");
    botao_sel = al_load_bitmap("recursos/roxo11.png");
    fundo_menu = al_load_bitmap("recursos/SANGUE.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",75,0);

    al_clear_to_color(al_map_rgb(0,0,0));

    al_draw_bitmap(fundo_menu,0,0,0);



    if(sel1){
        al_draw_bitmap(botao_sel,LARGURA *0.37,ALTURA*0.80,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.37,ALTURA*0.80,0);
    }
    if(sel2){
        al_draw_bitmap(botao_sel,LARGURA *0.58,ALTURA*0.80,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.58,ALTURA*0.80,0);
    }

    al_draw_text(fonte,al_map_rgb(255,255,255),252,615,ALLEGRO_ALIGN_CENTRE,"VOLTAR PARA AJUDAR");
    al_draw_text(fonte,al_map_rgb(255,255,255),1080,615,ALLEGRO_ALIGN_CENTRE,"SEGUIR EM FRENTE");



    al_destroy_bitmap(botao);
    al_destroy_bitmap(botao_sel);
    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}

void executarParte14_seguirfrente()
{
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_SAMPLE * som = NULL;
    bool sair = false;

    som = al_load_sample("recursos/15NAOENTROU.ogg");
    al_play_sample(som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    fila_eventos = al_create_event_queue();
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());



    while(!sair){

        desenharparte14_seguirfrente();
        al_flip_display();

        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                case ALLEGRO_KEY_ENTER:
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    al_destroy_event_queue(fila_eventos);

                    al_stop_samples();
                    executarParte16();
                    sair = true;

                    fila_eventos = al_create_event_queue();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(som);

}

void desenharparte14_seguirfrente()
{
    ALLEGRO_BITMAP *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    fundo_menu = al_load_bitmap("recursos/pexelsphoto1.jpg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",80,0);
    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_bitmap(fundo_menu,0,0,0);

    al_draw_text(fonte,al_map_rgb(255,0,0),693,210,ALLEGRO_ALIGN_CENTRE,"APOS A ANIMACAO PRESSIONE ENTER PARA PROSSEGUIR");

    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}

void executarParte14_1()
{
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_SAMPLE * som = NULL;
    bool sair = false;

    som = al_load_sample("recursos/1.ogg");
    al_play_sample(som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    fila_eventos = al_create_event_queue();
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());



    while(!sair){

        desenharparte14_seguirfrente();
        al_flip_display();

        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                case ALLEGRO_KEY_ENTER:
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    al_destroy_event_queue(fila_eventos);

                     al_stop_samples();
                     executarParte16();
                     sair = true;

                    fila_eventos = al_create_event_queue();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(som);

}

void desenharparte14_1()
{
    ALLEGRO_BITMAP *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    fundo_menu = al_load_bitmap("recursos/ConfusedStories2.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",80,0);

    al_clear_to_color(al_map_rgb(0,0,0));
    //al_draw_bitmap(fundo_menu,0,0,0);

    al_draw_text(fonte,al_map_rgb(255,0,0),693,210,ALLEGRO_ALIGN_CENTRE,"APOS A ANIMACAO PRESSIONE ENTER PARA PROSSEGUIR");

    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}


void executarParte15()
{
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_SAMPLE * som = NULL;
    bool sair = false;

    som = al_load_sample("recursos/16VOLTOU.ogg");
    al_play_sample(som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    fila_eventos = al_create_event_queue();
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());



    while(!sair){

        desenharParte15();
        al_flip_display();

        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                case ALLEGRO_KEY_ENTER:
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    al_destroy_event_queue(fila_eventos);

                    al_stop_samples();
                    executarParte16();
                    sair = true;

                    fila_eventos = al_create_event_queue();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(som);

}

void desenharParte15()
{
    ALLEGRO_BITMAP *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    fundo_menu = al_load_bitmap("recursos/ConfusedStories2.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",80,0);

    al_clear_to_color(al_map_rgb(0,0,0));
    //al_draw_bitmap(fundo_menu,0,0,0);

    al_draw_text(fonte,al_map_rgb(255,0,0),693,210,ALLEGRO_ALIGN_CENTRE,"APOS A ANIMACAO PRESSIONE ENTER PARA PROSSEGUIR");

    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}


void executarParte15_1()
{
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_SAMPLE * som = NULL;
    bool sair = false;

    som = al_load_sample("recursos/16NAOVOLTOU.ogg");
    al_play_sample(som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    fila_eventos = al_create_event_queue();
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());



    while(!sair){

        desenharParte15_1();
        al_flip_display();

        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                case ALLEGRO_KEY_ENTER:
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    al_destroy_event_queue(fila_eventos);

                    al_stop_samples();
                    executarParte16();
                    sair = true;

                    fila_eventos = al_create_event_queue();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(som);

}

void desenharParte15_1()
{
    ALLEGRO_BITMAP *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    fundo_menu = al_load_bitmap("recursos/ConfusedStories2.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",80,0);

    al_clear_to_color(al_map_rgb(0,0,0));
    //al_draw_bitmap(fundo_menu,0,0,0);

    al_draw_text(fonte,al_map_rgb(255,0,0),693,210,ALLEGRO_ALIGN_CENTRE,"APOS A ANIMACAO PRESSIONE ENTER PARA PROSSEGUIR");

    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}

void executarParte16()
{
    bool sair = false;
    bool botao1 = false, botao2 = false;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_BITMAP *botao = NULL;
    ALLEGRO_SAMPLE * som = NULL;

    fila_eventos = al_create_event_queue();
    botao = al_load_bitmap("recursos/preto11.png");
    som = al_load_sample("recursos/ESCOLHAARMA.ogg");
    al_play_sample(som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    al_register_event_source(fila_eventos, al_get_mouse_event_source());///faz com que a fila atenda a eventos gerados pelo mouse
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());

    while(!sair){

        desenharParte16(botao1, botao2);
        al_flip_display();

        while(!al_event_queue_is_empty(fila_eventos)){
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_MOUSE_AXES){
                if(evento.mouse.x >= LARGURA*0.27 && evento.mouse.x <= LARGURA *0.27+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = true;///muda a imagem
                    botao2 = false;
                }
                else if(evento.mouse.x >= LARGURA*0.55 && evento.mouse.x <= LARGURA *0.55 + al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA *0.80&& evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                    botao1 = false;
                    botao2 = true;
                }
                else
                {
                    botao1 = false;
                    botao2 = false;
                }
            }
            else if(evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                if(evento.mouse.x >= LARGURA*0.27 && evento.mouse.x <= LARGURA *0.27+ al_get_bitmap_width(botao)&&
                        evento.mouse.y >= ALTURA*0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                {
                     ///BOTAO PEGAR ARMA.
                     al_stop_samples();
                    executarParte17();
                    sair = true;
                }

                else
                {
                    if(evento.mouse.x >= LARGURA*0.55 && evento.mouse.x <= LARGURA *0.55+ al_get_bitmap_width(botao)&&
                            evento.mouse.y >= ALTURA*0.80 && evento.mouse.y <= ALTURA*0.80 + al_get_bitmap_height(botao))
                    {
                        ///BOTAO CONTINUAR CORRENDO
                        al_stop_samples();
                        executarParte17_1();
                        sair = true;
                    }
                }
            }
            else if(evento.type == ALLEGRO_EVENT_KEY_DOWN){
                switch(evento.keyboard.keycode){
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_mouse_event_source());
    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());

    al_destroy_bitmap(botao);
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(som);

}

void desenharParte16(bool sel1, bool sel2)
{
    ALLEGRO_BITMAP *botao = NULL, *botao_sel = NULL, *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    botao = al_load_bitmap("recursos/preto11.png");
    botao_sel = al_load_bitmap("recursos/roxo11.png");
    fundo_menu = al_load_bitmap("recursos/portaluvas.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",75,0);

    al_clear_to_color(al_map_rgb(0,0,0));

    //al_draw_bitmap(fundo_menu,0,0,0);



    if(sel1){
        al_draw_bitmap(botao_sel,LARGURA *0.27,ALTURA*0.80,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.27,ALTURA*0.80,0);
    }
    if(sel2){
        al_draw_bitmap(botao_sel,LARGURA *0.55,ALTURA*0.80,0);
    }
    else{
        al_draw_bitmap(botao,LARGURA *0.55,ALTURA*0.80,0);
    }


    al_draw_text(fonte,al_map_rgb(255,0,0),693,210,ALLEGRO_ALIGN_CENTRE,"ESCOLHA...");
    al_draw_text(fonte,al_map_rgb(255,255,255),220,615,ALLEGRO_ALIGN_CENTRE,"PEGAR ARMA.");
    al_draw_text(fonte,al_map_rgb(255,255,255),1080,615,ALLEGRO_ALIGN_CENTRE,"CONTINUAR CORRENDO");



    al_destroy_bitmap(botao);
    al_destroy_bitmap(botao_sel);
    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}

void executarParte17()
{
     ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_SAMPLE * som = NULL;
    bool sair = false;

    som = al_load_sample("recursos/17PEGOUARMA.ogg");
    al_play_sample(som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    fila_eventos = al_create_event_queue();
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());



    while(!sair){

        desenharParte17();
        al_flip_display();

        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                case ALLEGRO_KEY_ENTER:
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    al_destroy_event_queue(fila_eventos);

                    al_stop_samples();
                    executarFIM();
                    sair = true;

                    fila_eventos = al_create_event_queue();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(som);


}

void desenharParte17()
{
    ALLEGRO_BITMAP *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    fundo_menu = al_load_bitmap("recursos/ConfusedStories2.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",80,0);

    al_clear_to_color(al_map_rgb(0,0,0));
    //al_draw_bitmap(fundo_menu,0,0,0);

    al_draw_text(fonte,al_map_rgb(255,0,0),693,210,ALLEGRO_ALIGN_CENTRE,"APOS A ANIMACAO PRESSIONE ENTER PARA PROSSEGUIR");

    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);


}


void executarParte17_1()
{
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_SAMPLE * som = NULL;
    bool sair = false;

    som = al_load_sample("recursos/17NAOPEGOUARMA.ogg");
    al_play_sample(som,1.0,0.0,1.0,ALLEGRO_PLAYMODE_ONCE,NULL);

    fila_eventos = al_create_event_queue();
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());



    while(!sair){

        desenharParte17_1();
        al_flip_display();

        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                case ALLEGRO_KEY_ENTER:
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    al_destroy_event_queue(fila_eventos);

                    al_stop_samples();
                    executarFIM();
                    sair = true;

                    fila_eventos = al_create_event_queue();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(som);

}

void desenharParte17_1()
{
    ALLEGRO_BITMAP *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    fundo_menu = al_load_bitmap("recursos/ConfusedStories2.jpeg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",80,0);

    al_clear_to_color(al_map_rgb(0,0,0));
    //al_draw_bitmap(fundo_menu,0,0,0);

    al_draw_text(fonte,al_map_rgb(255,0,0),693,210,ALLEGRO_ALIGN_CENTRE,"APOS A ANIMACAO PRESSIONE ENTER PARA PROSSEGUIR");

    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);


}


void executarFIM()
{
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_SAMPLE * som = NULL;
    bool sair = false;
    ALLEGRO_AUDIO_STREAM * musica = NULL;


    fila_eventos = al_create_event_queue();
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());

    musica = al_load_audio_stream("recursos/MUSICINTRO.ogg",4,1024);
    al_set_audio_stream_playmode(musica,ALLEGRO_PLAYMODE_LOOP);
    al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());

al_set_audio_stream_playing(musica,true);



    while(!sair){

        desenharFIM();
        al_flip_display();

        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                case ALLEGRO_KEY_ENTER:
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    al_destroy_event_queue(fila_eventos);

                    al_stop_samples();
                    al_rest(4.0);

                    executarCreditos();
                    sair = true;

                    fila_eventos = al_create_event_queue();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
    al_destroy_event_queue(fila_eventos);
    al_destroy_audio_stream(musica);

}

void desenharFIM()
{
    ALLEGRO_BITMAP *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    fundo_menu = al_load_bitmap("recursos/intro.png");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",80,0);

    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_bitmap(fundo_menu,0,0,0);

    al_draw_text(fonte,al_map_rgb(255,255,0),693,200,ALLEGRO_ALIGN_CENTRE,"PRESSIONE ENTER PARA INICIAR OS CREDITOS");



    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}



void executarCreditos()
{
    ALLEGRO_EVENT_QUEUE * fila_eventos = NULL;
    ALLEGRO_SAMPLE * som = NULL;
    bool sair = false;
    ALLEGRO_AUDIO_STREAM * musica = NULL;


    fila_eventos = al_create_event_queue();
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());

    musica = al_load_audio_stream("recursos/MUSICINTRO.ogg",4,1024);
    al_set_audio_stream_playmode(musica,ALLEGRO_PLAYMODE_LOOP);
    al_attach_audio_stream_to_mixer(musica, al_get_default_mixer());

al_set_audio_stream_playing(musica,true);



    while(!sair){

        desenharCreditos();
        al_flip_display();

        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);

            if(evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                case ALLEGRO_EVENT_MOUSE_AXES:
                    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
                    al_destroy_event_queue(fila_eventos);

                    al_stop_samples();
                    //executarFIM();
                    sair = true;

                    fila_eventos = al_create_event_queue();
                    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
                    sair = true;
                    break;
                }
            }
        }
    }

    al_unregister_event_source(fila_eventos, al_get_keyboard_event_source());
    al_destroy_event_queue(fila_eventos);
    al_destroy_audio_stream(musica);


}

void desenharCreditos()
{
    ALLEGRO_BITMAP *fundo_menu = NULL;
    ALLEGRO_FONT * fonte = NULL;

    fundo_menu = al_load_bitmap("recursos/acabou.jpg");
    fonte = al_load_ttf_font("recursos/Ancherr.ttf",80,0);

    al_clear_to_color(al_map_rgb(0,0,0));
    al_draw_bitmap(fundo_menu,0,0,0);



    al_destroy_bitmap(fundo_menu);
    al_destroy_font(fonte);

}
