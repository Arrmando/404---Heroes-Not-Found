# 404---HEROES-NOT-FOUND

## Estrutura do Projeto

Este projeto usa uma variação da arquitetura MVVM (Model-View-ViewModel) adaptada para C++. A Visualização e o ViewModel são combinados em um único diretório `ui` para simplificar o gerenciamento de componentes inter-relacionados. Esta arquitetura é projetada tendo em mente os princípios de UDF (Fluxo de Dados Unidirecional) e SST (Fonte Única de Verdade) para tornar a base de código mais fácil de entender, manter e testar, especialmente para desenvolvedores que são novos nesses padrões de arquitetura.

### Visão Geral do Sistema de Arquivos

```
404---HEROES-NOT-FOUND/
├── assets/
│   ├── data/
│   ├── images/
│   └── sounds/
├── build/
├── libs/
├── src/
│   ├── model/
│   └── ui/
│       ├── view/
│       └── view_model/
├── util/
├── .gitignore
└── README.md
```

### Descrição dos Diretórios

*   **`assets/`**: Contém todos os ativos estáticos usados pelo jogo.
    *   **`data/`**: Arquivos de dados, como arquivos JSON ou XML, que definem configurações do jogo, níveis, itens, etc.
    *   **`images/`**: Arquivos de imagem para texturas, sprites, fundos e outros elementos visuais.
    *   **`sounds/`**: Arquivos de áudio para efeitos sonoros e música.

*   **`build/`**: Diretório temporário onde os executáveis compilados, arquivos de objeto e outros artefatos de construção são colocados. Este diretório geralmente não é rastreado no controle de versão.

*   **`libs/`**: Bibliotecas externas ou módulos de terceiros usados pelo projeto.

*   **`src/`**: O código-fonte principal do jogo.
    *   **`model/`**: Contém as classes e a lógica principais do jogo. Isso inclui a representação de dados do estado do jogo (por exemplo, classes `Player`, `Monster`, `Item`) e a lógica para manipular esses dados (por exemplo, mecânica de combate, progressão de personagem).
    *   **`ui/`**: Responsável pela interface do usuário. Nesta arquitetura, ele combina tanto a **View** quanto o **ViewModel** do MVVM tradicional:
        *   **View**: Lida com o layout visual e a exibição dos elementos da IU. Interage com o usuário e encaminha a entrada do usuário para o ViewModel.
        *   **ViewModel**: Atua como intermediário entre o Model e a View. Ele expõe os dados do Model de uma maneira amigável à View e lida com as ações do usuário (comandos) da View.
    *   **`view/`**: Componente visual que usa o viewmodel para atualizações de tela.

*   **`util/`**: Contém funções utilitárias ou classes auxiliares que são usadas em várias partes do projeto.

*   **`.gitignore`**: Especifica arquivos e diretórios que o Git deve ignorar (não rastrear).

*   **`README.md`**: Este arquivo, fornecendo uma visão geral do projeto e sua estrutura.

### Notas de Arquitetura

*   **MVVM (Model-View-ViewModel) Adaptado**: Embora o projeto tenha como objetivo seguir os princípios do MVVM, a View e o ViewModel são combinados no diretório `ui`. Isso significa que as classes de IU (View) e suas classes lógicas correspondentes (ViewModel) são mantidas próximas umas das outras.
*   **Ligação de dados**: Uma forma de ligação de dados entre a `ui` (View e ViewModel) e o `model` precisará ser implementada. Isso pode ser feito usando o padrão Observer ou outros mecanismos de reação para garantir que a IU seja atualizada quando o estado do jogo no Model for alterado.
*   **Injeção de Dependência**: Para um acoplamento mais flexível e melhor capacidade de teste, considere usar um framework ou técnicas de injeção de dependência para gerenciar as dependências entre o Model, a View e o ViewModel.

### Explicação do UDF (Fluxo de Dados Unidirecional) e SST (Fonte Única de Verdade)

Esta arquitetura incorpora os princípios de UDF (Fluxo de Dados Unidirecional) e SST (Fonte Única de Verdade) para melhorar a capacidade de manutenção e a previsibilidade.

#### UDF (Fluxo de Dados Unidirecional)

O UDF é um padrão de design onde os dados em seu aplicativo fluem em uma única direção. Isso torna o fluxo de dados mais previsível e fácil de entender. Aqui está como ele se aplica à arquitetura:

1. **Visualização (com ViewModel integrado)**:
    
    *   A Visualização observa o estado no ViewModel e é renderizada novamente quando o estado muda.
    *   Ele captura as ações do usuário (por exemplo, cliques em botões) e invoca os métodos correspondentes (Intenções ou Comandos) no ViewModel.
2. **ViewModel**:
    
    *   Contém o estado observável para a IU.
    *   Recebe Intenções da Visualização.
    *   Interage com o Modelo para executar a lógica do jogo com base nas Intenções.
    *   Atualiza seu estado observável com base nas mudanças no Modelo.
3. **Modelo**:
    
    *   Contém os dados e a lógica do jogo.
    *   Atualiza seu estado com base nas interações do ViewModel.
    *   Notifica o ViewModel sobre as mudanças de estado (por exemplo, usando o padrão Observer).
    

**Fluxo de Dados Simplificado:**

```
Visualização (observa o estado) --(Ação do usuário)--> ViewModel --(Intenção)--> Modelo --(Mudança de estado)--> ViewModel --(Atualização de estado)--> Visualização
```

#### SST (Fonte Única de Verdade)

SST significa que cada pedaço de dados deve ter uma única fonte autoritativa no sistema. Em nosso caso:

*   **Modelo**: Atua como a única fonte de verdade para o estado do jogo.
*   **ViewModel**: Deriva e expõe o estado do Modelo, mas não armazena dados independentes do jogo.
*   **Visualização**: Não contém nenhum estado mutável, exibindo apenas as informações do ViewModel.

#### Benefícios do UDF e SST

*   **Previsibilidade**: O fluxo de dados unidirecional torna mais fácil entender como o estado muda.
*   **Capacidade de Teste**: Os componentes podem ser testados independentemente.
*   **Capacidade de Manutenção**: A depuração e a manutenção do código tornam-se mais fáceis com um fluxo de dados consistente e uma única fonte de verdade.
*   **Clareza**: A separação de preocupações torna o código mais organizado e compreensível.

#### Exemplo de Jogo Clicker de RPG

1. **Ação do Usuário**: O jogador clica no botão "Atacar Monstro".
2. **Visualização para ViewModel**: A Visualização chama o método `attackMonster()` no ViewModel.
3. **ViewModel para Modelo**: O ViewModel chama o método `attackMonster()` correspondente no Modelo.
4. **Atualização do Modelo**: O Modelo atualiza a saúde do monstro, o ouro do jogador, etc., com base na lógica de ataque.
5. **Notificação do Modelo**: O Modelo notifica o ViewModel de que seu estado mudou.
6. **Atualização do ViewModel**: O ViewModel atualiza seus campos observáveis (por exemplo, `monsterHealth`, `playerGold`).
7. **Atualização da Visualização**: A Visualização atualiza automaticamente os elementos da IU para mostrar os valores atualizados.

### Guia de Contribuição

1. **Estrutura**: Siga a estrutura de diretório e as convenções de nomenclatura estabelecidas.
2. **Estilo de codificação**: Siga as diretrizes de estilo de codificação C++ consistentes em todo o projeto.
3. **Documentação**: Mantenha o código bem comentado e atualize a documentação conforme necessário.
4. **Testes**: Escreva testes de unidade para novas funcionalidades, especialmente para as classes no `model`.

### Links UML:
1. **Ficha**:  https://lucid.app/lucidchart/51e15665-4458-46f7-9239-b45c6e16ee9d/edit?viewport_loc=-130%2C-192%2C5713%2C2798%2CHWEp-vi-RSFO&invitationId=inv_818e31c4-3184-4dc9-8c62-0607c3d38d67
2. **InterfaceGráfica**:  https://lucid.app/lucidchart/9cb1650a-1c5e-443c-a44b-0280fa08f1da/edit?view_items=xjFJOcZq0O16&invitationId=inv_edcb17ae-dbe9-4af1-80ba-9172aa813db7
3. **Combate**:  https://lucid.app/lucidchart/7b504578-92c7-4290-8840-85f5eeef0bce/edit?viewport_loc=-2401%2C143%2C4490%2C2199%2C0_0&invitationId=inv_61148b24-fc1f-4a19-897c-9a5da20b8ef2


### Instruções para compilar:

Esse projeto faz uso de bibliotecas de terceiros para determinadas situações, assim, deve-se adicionar essas como submódulos do projeto para torná-lo funcional:

**Compilando o cppcoro manualmente**
``` bash
git submodule add https://github.com/andreasbuhr/cppcoro.git libs/cppcoro
git submodule update --init --recursive
cd libs/cppcoro/
mkdir build && cd build
cmake ..
make
```

Este README fornece uma explicação abrangente do sistema de arquivos, arquitetura e princípios de design do projeto. Consulte a documentação do código para obter informações mais detalhadas.