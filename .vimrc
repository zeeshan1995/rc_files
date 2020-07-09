
filetype plugin indent on
"color default

set nu
set cindent

set autoindent
set tabstop=4
set shiftwidth=4
set softtabstop=4
set expandtab

set wildmenu
set showmatch

autocmd BufReadPost *
     \ if line("'\"") > 0 && line("'\"") <= line("$") |
     \   exe "normal! g`\"" |
     \ endif

set hlsearch 
set laststatus=2
" visualize special characters
set list
set listchars=tab:\ \ ,trail:.,nbsp:%,extends:>,precedes:<
nnoremap <F3> <C-w>gf:e %<.cpp<CR>
inoremap <F1> <Esc>:w<CR>i
nnoremap <F9> gT
nnoremap <F10> gt


set matchpairs+=<:>

hi clear SpellBad
hi SpellBad cterm=underline

"execute pathogen#infect()
"
"source ~/.vim/.syntastic.vimrc
