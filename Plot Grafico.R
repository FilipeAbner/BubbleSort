setwd("F:/Ciencia da Computa�ao/Busca e Ordenacao/Trabalho 1 BubbleSort")
dados<-read.csv("TabelaDeAcessos.csv")
library(dplyr)
library(ggplot2)

tabela<-data.frame(Acessos=dados$Acessos, Qtd.Elementos= dados$Qtd.Elementos)

ggplot(dados) + 
  aes(Qtd.Elementos,Acessos) + 
  geom_line(lwd = 0.9, color = "red") + 
  ylab("Qtd.Acessos") + 
  xlab("Qtd.Elementos") + 
  ggtitle('Acessos � Mem�ria') 
  
