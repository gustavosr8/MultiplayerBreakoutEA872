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

### Instalação

Para instalar, certifique-se de ter um terminal aberto no diretório ```bin```, e, então, digite os comandos abaixo, em ordem:

- ```mkdir bin```
- ```cd bin```
- ```cmake ../```
- ```make```
- ```./Breakout```

## Como jogar

O objetivo do jogo é fazer a bolinha vermelha colidir com todos os tijolos enquanto não deixa ela cair. Para isso, há uma barrinha na parte inferior da tela que pode ser controlada com os direcionais esquerdo e direito.
- Tecla ```S```: Inicia o jogo.
- Tecla ```Esc```: Encerra o jogo a qualquer momento.
- Tecla ```Espaço```: Caso pressionada, prende a bolinha na barra, e a solta ao soltar a tecla.

## Documentação

A documentação com explicação do código pode ser acessada [aqui](https://gustavosr8.github.io/DocBreakout/index.html).