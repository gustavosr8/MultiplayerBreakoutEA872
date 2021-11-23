# Multiplayer Atari Breakout

Esse é um projeto desenvolvido na disciplina de EA872 - Laboratório de Programação de Software Básico da UNICAMP, ministrada pelo professor Tiago Tavares.

O objetivo é desenvolver uma versão de multiplayer massivo inspirado no jogo [Breakout](https://en.wikipedia.org/wiki/Breakout_(video_game)). Nele, cada jogador deve proteger o seu conjunto de blocos enquanto tenta destruir o conjunto de blocos dos demais jogadores. No momento que todo o conjunto de algum jogador for destruido, este será eliminado da partida. Ganha o último que permanecer no jogo.

## Instalando o Jogo

### Dependências

O jogo utiliza bibliotecas e programas externos para a sua instalação e para o seu funcionamento. Certifique-se de tê-los instalado para que o programa possa ser montado corretamente.

- [CMake](https://cmake.org/)
- [SDL2](https://www.libsdl.org/download-2.0.php)
- [SDL2_image](https://www.libsdl.org/projects/SDL_image/)
- [SDL2_ttf](https://www.libsdl.org/projects/SDL_ttf/)
- [Boost](https://www.boost.org/)
- [Doxygen](https://www.doxygen.nl/index.html) 

### Instalação

Para instalar, certifique-se de ter um terminal aberto no diretório ```bin```, e, então, digite os comandos abaixo, em ordem:

- ```mkdir bin```
- ```cd bin```
- ```cmake ../```
- ```make```

## Como jogar
Para iniciar o jogo, primeiro é necessário iniciar o server. Isso pode ser feito por meio do comando `./BreakoutServer`. Após isso, todos os jogadores devem abrir os clientes, com o comando `./Breakout`. Para cada jogador conectado, pressione 0 no terminal do servidor, e depois 1 quando todos estiverem conectados, iniciando a aplicação. O jogo tem dois modos: singleplayer e multiplayer.

### Singlepayer
O objetivo do siglepayer é o jogador destruir todos os tijolos brancos, acertando a bolinha neles, ao mesmo tempo que não pode deixar a bolinha cair. Ganha se destruir todos os tijolos e perde se perder todas as vidas.

### Multiplayer
O objetivo do multiplayer é destruir todos os tijolos dos outros jogadores enquanto defende os seus tijolos. Perde o jogador que tiver todos os tijolos destruidos, e ganha o último jogador a perder.

### Controles
- Tecla ```S```: Inicia o jogo.
- Tecla ```Esc```: Encerra o jogo a qualquer momento.
- Tecla ```Espaço```: Caso pressionada, prende a bolinha na barra, e a solta ao soltar a tecla.
- Tecla ```Direcionais```: Movem a barrinha

## Documentação

A documentação com explicação do código pode ser acessada [aqui](https://gustavosr8.github.io/DocBreakout/index.html).