import { Component, OnInit } from '@angular/core';
import { MessageService } from '../services/message.service';


@Component({
  selector: 'app-message',
  standalone: true,
  template:'<h1>{{ message }}</h1>',
  providers: [MessageService]
})
export class MessageComponent implements OnInit {
  message: string = '';
  isLoading: boolean = true;

  constructor(private messageService: MessageService) { }

  ngOnInit(): void {
    this.messageService.getMessage().subscribe(
      data => {
        this.message = data.message;
        this.isLoading = false;
      },
      error => {
        console.error('Error fetching message:', error);
        this.message = 'Failed to load message.';
        this.isLoading = false;
      }
    );
  }
}
