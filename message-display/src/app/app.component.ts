import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { HttpClientModule } from '@angular/common/http';
import { MessageComponent } from '../message/message.component';

@Component({
  selector: 'app-root',
  standalone: true,
  imports: [RouterOutlet, HttpClientModule, MessageComponent],
  template: `<app-message></app-message>`, 
  styleUrls: ['./app.component.css'],

})
export class AppComponent {
}
