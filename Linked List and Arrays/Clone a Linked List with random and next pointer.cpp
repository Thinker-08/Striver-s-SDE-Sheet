Node* copyRandomList(Node* head) 
{
         if(!head)
            return NULL;
        Node *curr = head;
        Node *temp; 
        while(curr) {
            temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = temp;
        }
        curr = head;
        while(curr) {
            curr->next->random = curr->random ? curr->random->next : NULL;
            curr = curr->next->next;
        }
        Node *original = head;
        Node *copy = head->next;
        Node *result_ptr = copy;
        
        while(original && copy) {
            original->next = copy->next;
            copy->next = copy->next ? copy->next->next : NULL;
            original = original->next;
            copy = copy->next;
        }
        return result_ptr;
}