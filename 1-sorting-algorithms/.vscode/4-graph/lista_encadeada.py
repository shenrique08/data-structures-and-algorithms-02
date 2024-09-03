class Node:
    
    def __init__(self, valor):
        self.valor = valor
        self.proximo = None
        
        
    def obterValor(self):
        return self.valor
    
    
    def setProximo(self, proximo):
        self.proximo = proximo
        
        
    def obterProximo(self):
        return self.proximo
    
    
    
    
node1 = Node(4)
node2 = Node(3)

node1.setProximo(node2)
print(node1.obterProximo) # mostra o endereço do endereço que é apontado pelo node1
print(node1.obterProximo().obterValor())


