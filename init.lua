function startup()
    print('Iniciando...')
    dofile('receptor_apc220_teste_campo.lua')
end

-- Espera 4 segundos para iniciar o programa sendo possivel o timer ser finalizado com tmr.stop(0) para reprogramacao do ESP
-- Mudar o baud rate para 9600 bps para funcionar com o APC220. Alterar para 1200bps para longa distancia.
tmr.alarm(0,4000,0,uart.setup(0,9600,8,0,1) startup)
