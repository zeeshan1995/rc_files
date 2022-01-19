
" LANGUAGE SERVER
"
" > https://langserver.org/
" > https://github.com/autozimu/LanguageClient-neovim/blob/next/INSTALL.md
" > https://github.com/theia-ide/typescript-language-server

let g:LanguageClient_serverCommands = {
    \ 'javascript': ['/usr/local/bin/javascript-typescript-stdio'],
    \ 'python': ['/usr/local/bin/pyls'],
    \ 'cpp': ['/usr/bin/ccls'],
    \ 'go': ['gopls'],
    \ }

nnoremap C :call LanguageClient_contextMenu()<CR>
nnoremap <silent> K :call LanguageClient#textDocument_hover()<CR>
nnoremap <silent> gd :call LanguageClient#textDocument_definition()<CR>
nnoremap <silent> dg :tab :call LanguageClient#textDocument_definition()<CR>
nnoremap <silent> ds :vsp :call LanguageClient#textDocument_definition()<CR>
nnoremap <silent> rr :call LanguageClient#textDocument_rename()<CR>

