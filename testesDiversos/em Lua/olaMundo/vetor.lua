Vetor = {}--nova tabela vazia de nome "vetor"
Vetor.__index = Vetor --indicar que as funções bsucadas estao em vetor(classe) e nao vetor(objeto/tabela)

function Vetor:novo(tamanho)
    local self = setmetatable({}, Vetor)--criar nova tabela vazia(objeto instanciado) 
                                        --e associa metatables a nova tabela 
                                        --tabela que é instancia de vetor
    self.dados = {} --cria e iniizaliza tabela dados
    for i = 1, tamanho do
        self.dados[i] = ' '  -- Inicializa o vetor com espaços
    end
    return self
end

function Vetor:preencher(texto)
    for i = 1, #texto do --# indica o comprimento
        self.dados[i] = string.sub(texto, i, i)  -- atribui ao dados[] no index i a letra na string[] index i
    end
end

function Vetor:verificar(tamanhoT)
    for i = 1, tamanhoT do--int i, até tamanho t, faça
        if self.dados[i] == ' ' then
            error("erro: uma posição do vetor está vazia na posição " .. i)
        end
    end
end

function Vetor:paraString()
    local texto = "" --cria variavel string
    for i = 1, #self.dados do
        texto = texto .. self.dados[i]
    end
    return texto
end

return Vetor
