# Setup fzf
# ---------
if [[ ! "$PATH" == */home/zeeshan/.fzf/bin* ]]; then
  export PATH="${PATH:+${PATH}:}/home/zeeshan/.fzf/bin"
fi

# Auto-completion
# ---------------
[[ $- == *i* ]] && source "/home/zeeshan/.fzf/shell/completion.bash" 2> /dev/null

# Key bindings
# ------------
source "/home/zeeshan/.fzf/shell/key-bindings.bash"
