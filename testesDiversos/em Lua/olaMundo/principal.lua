-- Importa a classe Vetor do arquivo vetor.lua
local Vetor = require("vetor")

-- Função principal
function principal()
    -- Criando o vetor com 100 posições
    local vetor = Vetor:novo(100)

    -- String "olá mundo" que será alocada no vetor
    local mensagem = "olá mundo!"

    -- Preenchendo o vetor com a string
    vetor:preencher(mensagem)

    -- Verificando se as primeiras 9 posições estão preenchidas corretamente
    local limite = #mensagem --por algum motivo no mais funciona mas no metodo verificar da classe nao
    for i = 1, limite do
        if vetor.dados[i] == ' ' then
            print("A posição " .. i .. " está vazia.")
        end
    end
   --vetor:verificar(#mensagem)
   
    -- Convertendo o vetor para uma string e imprimindo o resultado
    local resultado = vetor:paraString()
    print(resultado)
end

-- Executa a função principal
principal()
