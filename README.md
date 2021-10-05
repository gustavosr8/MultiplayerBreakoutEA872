# Multiplayer Atari Breakout

Esse é um projeto desenvolvido na disciplina de EA872 - Laboratório de Programação de Software Básico da UNICAMP, ministrada pelo professor Tiago Tavares.

O objetivo é desenvolver uma versão de multiplayer massivo inspirado no jogo [Breakout](https://en.wikipedia.org/wiki/Breakout_(video_game)). Nele, cada jogador deve proteger o seu conjunto de blocos enquanto tenta destruir o conjunto de blocos dos demais jogadores. No momento que todo o conjunto de algum jogador for destruido, este será eliminado da partida. Ganha o último que permanecer no jogo.

## Instalando o Jogo

### Dependências

O jogo utiliza bibliotecas e programas externos para a sua instalação e para o seu funcionamento. Certifique-se de tê-los instalado para que o programa possa ser montado corretamente.

- [SDL2](https://www.libsdl.org/download-2.0.php)
- [CMake](https://cmake.org/)

### Instalação

Para instalar, certifique-se de ter um terminal aberto no diretório ```bin```, e, então, digite os comandos abaixo, em ordem:

-```mkdir bin```
-```cd bin```
- ```cmake ../```
- ```make```
- ```./Breakout``` 